#include "Dron.hh"

/*!
 * \brief Konstruktor parametryczny Drona
 */
Dron::Dron(int id, PzG::LaczeDoGNUPlota &Lacze, Wektor3D polozenie) : Lacze(Lacze)
{
    kat = 0;
    this->id = id;
    korpus = new Prostopadloscian(polozenie,50, 40, 40, "../datasets/korpus" 
                                  + std::to_string(id+1) + ".dat");
    korpus->Przesuniecie(polozenie);
    this->droga = this-> droga + polozenie;
}

/*!
 * \brief Metoda odpowiada za wznoszenie Drona
 */
void Dron::Lot_w_gore(double droga)
{
    Wektor3D gora;
    gora[2] = droga;

    korpus->Przesuniecie(gora);
    usleep(CZEKAJ);
}

/*!
 * \brief Metoda odpowiada za opadanie Drona
 */
void Dron::Lot_w_dol(double droga)
{
    Wektor3D dol;
    dol[2] = droga;

    korpus->Przesuniecie(dol);
    usleep(CZEKAJ);
}

/*!
 * \brief Metoda odpowiada za obrot Drona
 */
void Dron::Obrot(double kat)
{
    os = 'z';
    korpus->Obrot(MacierzObrotu(kat, os));
    usleep(CZEKAJ);
}

/*!
 * \brief Metoda odpowiada za przesuniecie Drona
 */
void Dron::Przesuniecie(double droga)
{
    Wektor3D przesun;
    Wektor3D lot;
    przesun[0] = droga;
    
    os = 'z';
    lot = MacierzObrotu(this->kat, os) * przesun;
    korpus->Przesuniecie(lot);
    usleep(CZEKAJ);
}

/*!
 * \brief Metoda odpowiada za sterowanie dronem
 */
void Dron::Steruj_dronem()
{
    double droga;
    double kat;
    std::cout << "  Podaj kierunek lotu (kat w stopniach)> ";
    std::cin >> kat;
    std::cout << "\t\t     Podaj dlugosc lotu> ";
    std::cin >> droga;
    std::cout << std::endl;
    Lacze.DodajNazwePliku("../datasets/trasa_przelotu.dat", PzG::RR_Ciagly, 2);
    Trasa(kat, droga);
    std::cout << "  Realizacja przelotu ..." << std::endl << std::endl;
    std::cout << "  Wznoszenie ..." << std::endl << std::endl;
    for(int i=0; i<200; i++)
    {
        Lot_w_gore(1);
        Zapisz_do_pliku();
        
        Lacze.Rysuj(); 
    } 
    std::cout << "  Zmiana orientacji ..." << std::endl << std::endl;
    for(int i=0; i<kat; i++)
    {
        Obrot(1);
        Zapisz_do_pliku();
        Lacze.Rysuj();
    }
    std::cout << "  Lot do przodu ..." << std::endl << std::endl;
    this->kat=this->kat + kat;
    for(int i=0; i<droga; i++)
    {
        Przesuniecie(1);
        Zapisz_do_pliku();
        Lacze.Rysuj();
    }
    
    std::cout << "  Opadanie ..." << std::endl << std::endl;
    for(int i=0; i<200; i++)
    {
        Lot_w_dol(-1);
        Zapisz_do_pliku();
        Lacze.Rysuj();
    }
    Lacze.UsunOstatniaNazwe();
    Lacze.Rysuj();
}

/*!
 * \brief Metoda odpowiada za wyznaczenie trasy przelotu Drona
 */
void Dron::Trasa(double kat, double droga)
{
    Wektor3D nastepny;
    std::vector<Wektor3D> trasa;
    nastepny = korpus->zwroc_srodek();
    nastepny[2] = 0;
    trasa.push_back(nastepny);
    nastepny[2] = 200;
    trasa.push_back(nastepny);
    double radiany;
    radiany = kat * PI / 180;
    nastepny[0] = nastepny[0] + droga * cos(radiany);
    nastepny[1] = nastepny[1] + droga * sin(radiany);
    trasa.push_back(nastepny);
    nastepny[2] = 0;
    trasa.push_back(nastepny);

    std::fstream plik;
    
    plik.open("../datasets/trasa_przelotu.dat", std::ios::out);
    for(int i=0; i<(int)trasa.size(); i++)
    {
        plik << trasa[i] << std::endl;
    }
    plik.close();
}

/*!
 * \brief Metoda odpowiada za zapis Drona do pliku
 */
void Dron::Zapisz_do_pliku()
{
    korpus->Zapis_do_pliku();
}

