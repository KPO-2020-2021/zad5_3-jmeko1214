#include "Graniastoslup6.hh"


/*
 *  Tutaj sa zdefiniowane metody klasy Graniastoslup6. 
 *  Metody tworza graniastoslup i zapisuja go do pliku.
 */

 /******************************************************************************
 |  Konstruktor bezparametryczny klasy graniastoslup.                         |
 |  Argumenty:                                                                |
 |     brak                                                                   |
 */
Graniastoslup6::Graniastoslup6()
{
    for(int i=0; i<GRANIA_SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            wierzcholki[i][j] = 0;
        }
    }
}

/*****************************************************************************
 |  Konstruktor parametryczny klasy Graniastoslup6.                           |
 |  Argumenty:                                                                |
 |     srodek - srodek bryly, wokol ktorego dokonuje sie obrot                |
 |     promien - dlugosc promienia obrotu / boku graniastoslupa               |
 |     sNazwaPliku - przechowuje nazwe pliku zawierajacego wspolrzedne        |
 |  Zwraca:                                                                   |
 |     Obrocona bryle                                                         | 
 */
Graniastoslup6::Graniastoslup6(Wektor3D srodek, double promien, std::string sNazwaPliku)
{
    Wektor3D vector;
    wymiary = new Wektor3D(vector);
    this->srodek = srodek;
    this->sNazwaPliku = sNazwaPliku;

    for(int i=0; i<360; i+=60)
    {
        vector[0] = srodek[0] + promien * cos(i * PI / 180);
        vector[1] = srodek[1] + promien * sin(i * PI / 180);
        vector[2] = srodek[2] - 10;
        wierzcholki.push_back(vector);
        vector[0] = srodek[0] + promien * cos(i * PI / 180);
        vector[1] = srodek[1] + promien * sin(i * PI / 180);
        vector[2] = srodek[2] + 10;
        wierzcholki.push_back(vector);
    }
}


Graniastoslup6::~Graniastoslup6()
{
    delete wymiary;
}





