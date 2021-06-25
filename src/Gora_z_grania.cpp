#include "Gora_z_grania.hh"


/*
 *  Tutaj sa zdefiniowane metody klasy Gora_z_grania. 
 *  Metody tworza Gore_z_grania i zapisuja ja do pliku.
 */

 /*****************************************************************************
 |  Konstruktor bezparametryczny klasy Gora_z_grania.                         |
 |  Argumenty:                                                                |
 |     brak                                                                   |
 */
Gora_z_grania::Gora_z_grania()
{
    for(int i=0; i<WIERZCHOLKI; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            wierzcholki[i][j] = 0;
        }
    }
}

/******************************************************************************
 |  Konstruktor parametryczny klasy Gora_z_grania.                            |
 |  Argumenty:                                                                |
 |     wektor - zmienna przechowuje dlugosc wektora przesuniecia              |
 |     dlugosc - przechowuje polozenie wierzcholka na osi Oz                  |
 |     szerokosc - przechowuje polozenie wierzcholka na osi Oy                |
 |     wysokosc - przechowuje polozenie wierzcholka na osi Ox                 |
 |  Zwraca:                                                                   |
 |     Wierzcholki Gora_z_grania przesuniete o zadany wektor                  | 
 */
Gora_z_grania::Gora_z_grania(Wektor3D srodek, double dlugosc, double szerokosc, double wysokosc, std::string sNazwaPliku)
{
    this->sNazwaPliku = sNazwaPliku;
    this->srodek = srodek;
    double wym[] = {dlugosc, szerokosc, wysokosc};
    wymiary = new Wektor3D(wym);
    Wektor3D vector;

    vector[0] = srodek[0] - (dlugosc/2);
    vector[1] = srodek[1] + (szerokosc/2);
    vector[2] = srodek[2] - (wysokosc/2);
    wierzcholki.push_back(vector);
    
    vector[0] = srodek[0] + (dlugosc/2);
    vector[1] = srodek[1] - (szerokosc/2);
    vector[2] = srodek[2] - (wysokosc/2);
    wierzcholki.push_back(vector);

    vector[0] = srodek[0] + (dlugosc/2);
    vector[1] = srodek[1] + (szerokosc/2);
    vector[2] = srodek[2] - (wysokosc/2);
    wierzcholki.push_back(vector);

    vector[0] = srodek[0] + (dlugosc/2);
    vector[1] = srodek[1] - (szerokosc/2);
    vector[2] = srodek[2] + (wysokosc/2);
    wierzcholki.push_back(vector);

    vector[0] = srodek[0] + (dlugosc/2);
    vector[1] = srodek[1] + (szerokosc/2);
    vector[2] = srodek[2] + (wysokosc/2);
    wierzcholki.push_back(vector);

    vector[0] = srodek[0] - (dlugosc/2);
    vector[1] = srodek[1] - (szerokosc/2);
    vector[2] = srodek[2] - (wysokosc/2);
    wierzcholki.push_back(vector);

    vector[0] = srodek[0] - (dlugosc/2);
    vector[1] = srodek[1] + (szerokosc/2);
    vector[2] = srodek[2] - (wysokosc/2);
    wierzcholki.push_back(vector);

    vector[0] = srodek[0] + (dlugosc/2);
    vector[1] = srodek[1] - (szerokosc/2);
    vector[2] = srodek[2] - (wysokosc/2);
    wierzcholki.push_back(vector);
}

/******************************************************************************
 |  Realizuje zapis wspolrzednych Gora_z_grania do pliku                      |                                               
 |  Argumenty:                                                                |
 |     sNazwaPliku - nazwa pliku, do ktorego sa zapisywane wspolrzedne wierzch|
 |  Zwraca:                                                                   |
 |     True lub False                                                         |
 */
bool Gora_z_grania::Zapis_do_pliku()
{
    std::ofstream StrmPlikowy;

    StrmPlikowy.open(sNazwaPliku);
    if(!StrmPlikowy.is_open())
    {
        std::cerr << ":( Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
                  << ":( nie powiodla sie." << std::endl;
        return false;
    }
    for(int i=0; i<WIERZCHOLKI; i++)
    {
        StrmPlikowy << wierzcholki[i] << std::endl;
        if(i%2==1)
        {
            StrmPlikowy << std::endl;
        }
    }
    StrmPlikowy << wierzcholki[0] << std::endl;
    StrmPlikowy << wierzcholki[1] << std::endl;
    
    StrmPlikowy.close();
    return !StrmPlikowy.fail();
}

/******************************************************************************
 |  Przeciazenie operatora <<                                                 |                                               
 |  Argumenty:                                                                |
 |     strm - strumien wyjsciowy                                              |
 |     grania - zmienna pomocnicza do operacji na Gorze_z_grania              |
 |  Zwraca:                                                                   |
 |     Strumien wyjsciowy                                                     |
 */
std::ostream & operator << (std::ostream &strm, const Gora_z_grania &grania)
{
    for(int i=0; i<WIERZCHOLKI; i++)
    {
        strm << grania[i] << std::endl;
        if(i%2==1)
        {
            strm << std::endl;
        }
    }
    strm << grania[0] << std::endl;
    strm << grania[1] << std::endl;
    
    return strm;
}

/*!
 * \brief Destruktor wymiarow Gory_z_grania
 */
Gora_z_grania::~Gora_z_grania()
{
    delete wymiary;
}




