#include "BrylaGeometryczna.hh"



/******************************************************************************
 |  Przeciazenie operatora indeksowania, do odczytu i zapisu wsp. wierzch.    |                  
 |  Argumenty:                                                                |
 |     index - zmienna przechowuje indeks wierzcholka                         |
 |  Zwraca:                                                                   |
 |     Indeks wierzcholka prostopadlosciana                                   |
 */
Wektor3D & BrylaGeometryczna::operator [] (unsigned int index)
{
    if(wierzcholki.size()<=index)
    {
       return wierzcholki[index];
    }
    return wierzcholki[wierzcholki.size()-1];
}

/******************************************************************************
 |  Przeciazenie operatora indeksowania, do odczytu i zapisu wsp. wierzch.    |                  
 |  Argumenty:                                                                |
 |     index - zmienna przechowuje indeks wierzcholka                         |
 |  Zwraca:                                                                   |
 |     Indeks wierzcholka prostopadlosciana                                   |
 */
const Wektor3D & BrylaGeometryczna::operator [] (unsigned int index) const
{
    if(wierzcholki.size()<=index)
    {
       return wierzcholki[index];
    }
    return wierzcholki[wierzcholki.size()-1];
}

/******************************************************************************
 |  Metoda zwracajaca srodek bryly geometrycznej.				              |                  
 |  Argumenty:                                                                |
 |     brak						                                         |
 |  Zwraca:                                                                   |
 |     srodek - zwaraca srodek bryly geometrycznej                            |
 */
Wektor3D BrylaGeometryczna::zwroc_srodek() const
{
    return srodek;
}

std::string BrylaGeometryczna::ZwrocNazwaPliku() const
{
    return sNazwaPliku;
}

BrylaGeometryczna BrylaGeometryczna::operator + (Wektor3D przesun)
{
    BrylaGeometryczna przesuniecie;
    
    for(int i=0; i<(int)wierzcholki.size(); i++)
    {
        przesuniecie[i] = wierzcholki[i] + przesun;
    }
    return przesuniecie;    
}

/******************************************************************************
 |  Metoda klasy BrylaGeometryczna.                                           |
 |  Argumenty:                                                                |
 |     kat - zmienna przechowujaca wartosc kata w stopniach                   |
 |     krotnosc - zmienna przechowujaca liczbe obrotow o zadany kat           |
 |  Zwraca:                                                                   |
 |     Wartosc True                                                           |
 */
void BrylaGeometryczna::Obrot(Macierz3x3 macierz)  
{
    /*for(int i=0; i<(int)wierzcholki.size(); i++)
    {
        wierzcholki[i] = macierz * wierzcholki[i];
    }
    srodek = macierz * srodek;*/
    
    for(int i=0; i<(int)wierzcholki.size(); i++)
    {
        wierzcholki[i] = macierz * (wierzcholki[i]-srodek)+srodek;
    }
}

/******************************************************************************
 |  Realizuje przesuniecie wierzcholkow bryly o zadany wektor     |                                               
 |  Argumenty:                                                                |
 |     wektor - przechowuje wspolrzedne wektora przesuniecia                  |
 |  Zwraca:                                                                   |
 |     True lub False                                                         |
 */
void BrylaGeometryczna::Przesuniecie(Wektor3D przesun)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
{
    for(int i=0; i<(int)wierzcholki.size(); i++)
    {
        wierzcholki[i] = wierzcholki[i] + przesun;
    }
    srodek = srodek + przesun;
}

/******************************************************************************
 |  Realizuje zapis wierzcholkow bryly do pliku		     |                                               
 |  Argumenty:                                                                |
 |     brak						                        |
 |  Zwraca:                                                                   |
 |     True lub False                                                         |
 */
bool BrylaGeometryczna::Zapisz_do_pliku()
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
 |  Destruktor bezparametryczny		     |                                               
 |  Argumenty:                                                                |
 |     brak						                        |
 |  Zwraca:                                                                   |
 |     usuniete wymiary bryly                                                 |
 */
 BrylaGeometryczna::~BrylaGeometryczna()
 {
    delete wymiary;
 }




