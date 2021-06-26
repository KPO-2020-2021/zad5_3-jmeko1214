#include "Scena.hh"


/*!
 * \brief Konstruktor klasy Scena
 *
 *  Tutaj powstaje nasza scena (Plaszczyzna),
 *  na ktorej sa rysowane drony oraz przeszkody
 */
Scena::Scena()
{
    double polozenie[3] = {25.0, 25.0, 10.0};       //polozenie srodka pierwszego drona
    double polozenie2[3] = {100.0, 25.0, 10.0};     //polozenie srodka drugiego drona
    Wektor3D w1(polozenie);
    Wektor3D w2(polozenie2);
    wysokosc = polozenie[2];

    Lacze.DodajNazwePliku("../datasets/bryly_wzorcowe/plaszczyzna.dat",PzG::RR_Ciagly,2);
    Lacze.ZmienTrybRys(PzG::TR_3D);
    // Ustawienie zakresow poszczegolnych osi
    Lacze.UstawZakresY(-300,300);
    Lacze.UstawZakresX(-300,300);
    Lacze.UstawZakresZ(-100,400);
    dno = new Plaszczyzna(600, 600, 0, "../datasets/bryly_wzorcowe/plaszczyzna.dat");
    dno->Zapisz_do_pliku();   //plik plaszczyzny
    Lacze.DodajNazwePliku(("../datasets/korpus" + std::to_string(1) + ".dat").c_str(), PzG::RR_Ciagly, 2);
    Lacze.DodajNazwePliku(("../datasets/korpus" + std::to_string(2) + ".dat").c_str(), PzG::RR_Ciagly, 2);

    drony[0] = new Dron(0, Lacze, w1);
    drony[0]->Zapisz_do_pliku();     //plik drona
    drony[1] = new Dron(1, Lacze, w2);
    drony[1]->Zapisz_do_pliku();     //plik drona

    Lacze.Rysuj();
}

/*!
 * \brief Metoda odpowiada za rysowanie
 */
void Scena::Rysuj()
{
    Lacze.Rysuj();
}

/*!
 * \brief Metoda odpowiada za wybor Drona
 */
bool Scena::Wybor_drona()
{
    std::cout << "   Wybor aktywnego drona" << std::endl << std::endl;
    std::cout << " Wprowadz numer aktywnego drona> ";
    int numer;
    std::cin >> numer;
    this->numer = numer;
    if(numer==1 || numer==2)
    {
        if(numer==1)
        {
            std::cout << "    1 - Polozenie     <-- Dron aktywny" << std::endl;
            std::cout << "    2 - Polozenie " << std::endl;
        }
        if(numer==2)
        {
            std::cout << "    1 - Polozenie " << std::endl;
            std::cout << "    2 - Polozenie     <-- Dron aktywny " << std::endl;
        }
    }
    else
    {
        std::cerr << " Blad! Dozwolony wybor 1 lub 2 Drona!" << std::endl;
        return false;
    }
    return true;      
}

/*!
 * \brief Metoda odpowiada za sterowanie dronem
 */
void Scena::Steruj_dronem()
{
    //Dron dron;
    numer = this->numer-1;
    double droga;
    double kat;
    std::cout << "  Podaj kierunek lotu (kat w stopniach)> ";
    std::cin >> kat;
    std::cout << "\t\t     Podaj dlugosc lotu> ";
    std::cin >> droga;
    std::cout << std::endl;
    Lacze.DodajNazwePliku("../datasets/trasa_przelotu.dat", PzG::RR_Ciagly, 2);
    drony[numer]->Trasa(kat, droga);
    std::cout << "  Realizacja przelotu ..." << std::endl << std::endl;
    std::cout << "  Wznoszenie ..." << std::endl << std::endl;
    for(int i=0; i<200; i++)
    {
        drony[numer]->Lot_w_gore(1);
        drony[numer]->Zapisz_do_pliku();
        //Czy_kolizja(wysokosc);
        Lacze.Rysuj(); 
    } 
    std::cout << "  Zmiana orientacji ..." << std::endl << std::endl;
    for(int i=0; i<kat; i++)
    {
        drony[numer]->Obrot(1);
        drony[numer]->Zapisz_do_pliku();
        Lacze.Rysuj();
    }
    std::cout << "  Lot do przodu ..." << std::endl << std::endl;
    this->kat=this->kat + kat;
    for(int i=0; i<droga; i++)
    {
        drony[numer]->Przesuniecie(1, kat);
        drony[numer]->Zapisz_do_pliku();
        Lacze.Rysuj();
    }
    
    std::cout << "  Opadanie ..." << std::endl << std::endl;
    for(int i=0; i<200; i++)
    {
        drony[numer]->Lot_w_dol(-1);
        drony[numer]->Zapisz_do_pliku();
        Lacze.Rysuj();
    }
    Lacze.UsunOstatniaNazwe();
    Lacze.Rysuj();
}

/*!
 * \brief Metoda odpowiada za dodawanie przeszkod do sceny
 *  
 * Metoda pozwala na dodanie przeszkody, wybranie jej wymiarow
 * oraz na ustawienie polozenie srodka przeszkody na scenie 
 */
void Scena::Dodaj_przeszkode()
{
    int wybor;
    double OX, OY, OZ;      
    double x, y, z;

    std::cout << "   Wybierz rodzaj powierzchniowego elementu" << std::endl << std::endl;
    std::cout << "    1 - Gora z ostrym szczytem" << std::endl;
    std::cout << "    2 - Gora z grania" << std::endl;
    std::cout << "    3 - Plaskowyz" << std::endl << std::endl;
    std::cout << "  Wprowadz numer typu elementu> ";
    std::cin >> wybor;
    std::cout << std::endl << std::endl;
    std::cout << "  Podaj skale wzdluz kolejnych osi OX, OY, OZ." << std::endl;
    std::cout << "  Wprowadz skale: OX OY OZ> ";
    std::cin >> OX >> OY >> OZ;
    std::cout << std::endl;
    std::cout << "  Podaj wspolrzedne srodka podstawy x,y." <<std::endl;
    std::cout << "  Wprowadz wspolrzedne: x y> ";
    std::cin >> x >> y;

    z = OZ / 2;     //liczenie wspolrzednej wysokosci srodka bryly
    double srodek[3] = {x, y, z };   //polozenie srodka bryly
    Wektor3D w3(srodek);

    switch(wybor)
    {
        case 1:     //dodanie gory z ostrym szczytem
        {
            przeszkody.push_front(std::make_shared<Gora_ostra>(w3, OX, OY, OZ, "../datasets/przeszkody/gora_ostra.dat"));
            Lacze.DodajNazwePliku("../datasets/przeszkody/gora_ostra.dat", PzG::RR_Ciagly, 2);
            break;
        }
        case 2:     //dodanie gory z grania
        {            
            przeszkody.push_front(std::make_shared<Gora_z_grania>(w3, OX, OY, OZ, "../datasets/przeszkody/gora_z_grania.dat"));
            Lacze.DodajNazwePliku("../datasets/przeszkody/gora_z_grania.dat", PzG::RR_Ciagly, 2);
            break;
        }
        case 3:     //dodanie plaskowyzu
        {            
            przeszkody.push_front(std::make_shared<Plaskowyz>(w3, OX, OY, OZ, "../datasets/przeszkody/plaskowyz.dat"));
            Lacze.DodajNazwePliku("../datasets/przeszkody/plaskowyz.dat", PzG::RR_Ciagly, 2);
            break;
        } 
        default:
        {
            std::cerr << "  Blad! Wybrana przeszkoda nie istnieje!!!" << std::endl;
            std::cerr << "  Dopuszczalne mozliwosci to 1, 2 lub 3." << std::endl;
            break;
        }
    }
    for(std::list<std::shared_ptr<BrylaGeometryczna>>::const_iterator a = przeszkody.begin(); a != przeszkody.end(); a++)
    {
        (*a)->Zapisz_do_pliku();
    }
    Lacze.Rysuj();
    std::cout << std::endl;
    std::cout << "  Element dodany do sceny. " << std::endl;
}

/*!
* \brief Metoda odpowiada za sprawdzenie czy jest kolizja
*/
bool Scena::Czy_kolizja()//double wysokosc)
{
    //wysokosc = 50;
    
    std::cout << wysokosc << std::endl;

    return wysokosc;
}

/*!
 * \brief Destruktor, usuwa dno oraz drony
 */
Scena::~Scena()
{
    delete dno;
    delete drony[0];
    delete drony[1];
}
