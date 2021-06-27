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
            std::cout << "    2 - Polozenie     <-- Dron aktywny" << std::endl;
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
    numer = this->numer-1;
    double droga;
    double kat;
    double przedluz = 2*drony[numer]->Promien_drona();  //przedluzenie lotu o dwukrotnosc promienia drona
    std::cout << "  Podaj kierunek lotu (kat w stopniach)> ";
    std::cin >> kat;
    std::cout << "\t\t     Podaj dlugosc lotu> ";
    std::cin >> droga;
    std::cout << std::endl;
    Lacze.DodajNazwePliku("../datasets/trasa_przelotu.dat", PzG::RR_Ciagly, 2);
    drony[numer]->Trasa(kat, droga);
    std::cout << "  Realizacja przelotu ..." << std::endl << std::endl;
    std::cout << "  Wznoszenie ..." << std::endl << std::endl;
    for(int i=0; i<300; i++)
    {
        drony[numer]->Lot_w_gore(1);
        drony[numer]->Zapisz_do_pliku();
        
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
    while(Czy_kolizja() == true)
    {
        drony[numer]->Trasa(kat, przedluz);
        std::cout << "  Lot zostal wydluzony." << std::endl;
        std::cout << "  Poszukiwanie wolnego ladowiska." << std::endl << std::endl;
        for(int i=0; i<przedluz; i++)
        {
            drony[numer]->Przesuniecie(1, kat);
            drony[numer]->Zapisz_do_pliku();
            Lacze.Rysuj();
        }
    }
    std::cout << "  Opadanie ..." << std::endl << std::endl;
    for(int i=0; i<300; i++)
    {
        drony[numer]->Lot_w_dol(-1);
        drony[numer]->Zapisz_do_pliku();
        Lacze.Rysuj();
    }
    Lacze.UsunOstatniaNazwe();
    Lacze.Rysuj();
    std::cout << "  Polozenie Drona aktywnego (x,y):  " << drony[numer]->Wspolrzedna_X()
              << " " << drony[numer]->Wspolrzedna_Y() << std::endl << std::endl;
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
            promien_bryla[0] = sqrt((OX*OX/4+OY*OY/4)) + 5.0;
            srodek1[0] = srodek[0];
            srodek1[1] = srodek[1];
            break;
        }
        case 2:     //dodanie gory z grania
        {            
            przeszkody.push_front(std::make_shared<Gora_z_grania>(w3, OX, OY, OZ, "../datasets/przeszkody/gora_z_grania.dat"));
            Lacze.DodajNazwePliku("../datasets/przeszkody/gora_z_grania.dat", PzG::RR_Ciagly, 2);
            promien_bryla[1] = sqrt((OX*OX/4+OY*OY/4)) + 5.0;
            srodek2[0] = srodek[0];
            srodek2[1] = srodek[1];
            break;
        }
        case 3:     //dodanie plaskowyzu
        {            
            przeszkody.push_front(std::make_shared<Plaskowyz>(w3, OX, OY, OZ, "../datasets/przeszkody/plaskowyz.dat"));
            Lacze.DodajNazwePliku("../datasets/przeszkody/plaskowyz.dat", PzG::RR_Ciagly, 2);
            promien_bryla[2] = sqrt((OX*OX/4+OY*OY/4)) + 5.0;
            srodek3[0] = srodek[0];
            srodek3[1] = srodek[1];
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
* \brief Metoda odpowiada za sprawdzenie czy jest kolizja.
*  
*  Metoda liczy odleglosc srodka drona od srodka przeszkody
*  i zwraca true lub false. 
*  Promien = przekatna bryly + zapas (5.0)
*/
bool Scena::Czy_kolizja()
{
    double dron;             //zmienne do przechowania promienia aktywnego drona
    double spr1, spr2, spr3; //zmienne pomocnicze do liczenia sumy promieni bryly i drona
    double odleglosc[3];     //przechowuje odleglosc pomiedzy srodkiem drona i bryly       
    double srodek_d[2];      //przechowuje wspolrzedne srodka drona
    double odl_XY[3];        //zmienne pomocnicze, przechowuja odleglosc X i Y podniesione do kwadratu
    srodek_d[0] = drony[numer]->Wspolrzedna_X();
    srodek_d[1] = drony[numer]->Wspolrzedna_Y();

    odl_XY[0] = (srodek_d[0]-srodek1[0])*(srodek_d[0]-srodek1[0])+(srodek_d[1]-srodek1[1])*(srodek_d[1]-srodek1[1]);
    odl_XY[1] = (srodek_d[0]-srodek2[0])*(srodek_d[0]-srodek2[0])+(srodek_d[1]-srodek2[1])*(srodek_d[1]-srodek2[1]);
    odl_XY[2] = (srodek_d[0]-srodek3[0])*(srodek_d[0]-srodek3[0])+(srodek_d[1]-srodek3[1])*(srodek_d[1]-srodek3[1]);
        
    odleglosc[0] = sqrt(odl_XY[0]);
    odleglosc[1] = sqrt(odl_XY[1]);
    odleglosc[2] = sqrt(odl_XY[2]);
    
    dron=drony[numer]->Promien_drona();
    spr1 = dron + promien_bryla[0];
    spr2 = dron + promien_bryla[1];
    spr3 = dron + promien_bryla[2];

    if(spr1>odleglosc[0])
    {
        std::cout << " :(  Ladawisko niedostepne!" << std::endl;
        std::cout << " :(  Wykryto element powierzchni typu: GoraZOstrymSzczytem" << std::endl << std::endl;
        return true;
    }
    else if(spr2>odleglosc[1])
    {
        std::cout << " :(  Ladawisko niedostepne!" << std::endl;
        std::cout << " :(  Wykryto element powierzchni typu: GoraZDlugaGrania" << std::endl << std::endl;
        return true;
    }
    else if(spr3>odleglosc[2])
    {
        std::cout << " :(  Ladawisko niedostepne!" << std::endl;
        std::cout << " :(  Wykryto element powierzchni typu: Plaskowyz" << std::endl << std::endl;
        return true;
    }
    else
    {
        return false;
    }
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
