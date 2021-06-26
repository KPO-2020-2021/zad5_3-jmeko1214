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
void Dron::Przesuniecie(double droga, double kat)
{
    Wektor3D przesun;
    Wektor3D lot;
    przesun[0] = droga;
    //this->kat = this->kat + kat;
    
    os = 'z';
    lot = MacierzObrotu(kat, os) * przesun;
    korpus->Przesuniecie(lot);
    usleep(CZEKAJ);
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

