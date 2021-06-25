#ifndef GORA_OSTRA_HH
#define GORA_OSTRA_HH

#define WIERZCHOLKI 8

#include "BrylaGeometryczna.hh"
#include <iostream>                                                                                                                                                                                                                                                                                                                                         
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <cmath>

/*!
 *  \brief Definicja klasy Gora_ostra.
 *
 * Klasa reprezentuje gore z ostrym szczytem, obiekt skladajacy 
 * sie z 5 wierzcholkow. Wymiary gory mozna
 * ustawic za pomoca parametrow: dlugosc, szerokosc, wysokosc 
 * oraz wierzcholki zapisac do pliku. 
 */
class Gora_ostra: public BrylaGeometryczna {
    
  public:
/*!
 * \brief Konstruktor bezparametryczny klasy Gora_ostra
 */
    Gora_ostra();
    
/*!
 * \brief Konstruktor bezparametryczny klasy Gora_ostra
 */
    Gora_ostra( Wektor3D srodek, double dlugosc, double szerokosc, double wysokosc, std::string sNazwaPliku);                                                                                                                                                                                                                                                                      

/*!
 * \brief Metoda odpowiada za zapis wspolrzednych do pliku
 */
    bool Zapis_do_pliku();
    
/*!
 * \brief Destruktor, usuwa wymiary drona
 */
    ~Gora_ostra();
};
  
/*!
 * \brief Przeciazenie operatora wyswietlania.
 *
 * Przeciazenie sluzy do przekazywania do strumienia wspolrzednych
 * wierzcholkow Gora_ostra.
 */
//wyswietla wspolrzedne wierzcholkow gory z ostrym szczytem 
std::ostream& operator << ( std::ostream &Strm, const Gora_ostra &ostra); 

#endif


