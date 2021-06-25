#ifndef PLASKOWYZ_HH
#define PLASKOWYZ_HH

#define WIERZCHOLKI 8

#include "BrylaGeometryczna.hh"
#include <iostream>                                                                                                                                                                                                                                                                                                                                         
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <cmath>

/*!
 *  \brief Definicja klasy Plaskowyz.
 *
 * Klasa reprezentuje plaskowyz, obiekt skladajacy 
 * sie z 8 wierzcholkow. Wymiary plaskowyzu mozna
 * ustawic za pomoca parametrow: dlugosc, szerokosc, wysokosc 
 * oraz wierzcholki zapisac do pliku. Klasa Plaskowyz jest
 * zrobiona analogicznie do klasy Prostopadloscian.
 */
class Plaskowyz: public BrylaGeometryczna {
    
  public:
/*!
 * \brief Konstruktor bezparametryczny klasy Plaskowyz
 */
    Plaskowyz();
    
/*!
 * \brief Konstruktor parametryczny klasy Prostopadloscian
 */    
    Plaskowyz( Wektor3D srodek, double dlugosc, double szerokosc, double wysokosc, std::string sNazwaPliku);                                                                                                                                                                                                                                                                      

/*!
 * \brief Metoda odpowiada za zapis wspolrzednych do pliku
 */
    bool Zapis_do_pliku();
    
/*!
 * \brief Destruktor, usuwa wymiary drona
 */
    ~Plaskowyz();
};
  
/*!
 * \brief Przeciazenie operatora wyswietlania.
 *
 * Przeciazenie sluzy do przekazywania do strumienia wspolrzednych
 * wierzcholkow Plaskowyzu.
 */
//wyswietla wspolrzedne wierzcholkow plaskowyzu 
std::ostream& operator << ( std::ostream &Strm, const Plaskowyz &plaski); 

#endif


