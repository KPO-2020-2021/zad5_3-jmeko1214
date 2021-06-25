#ifndef GORA_Z_GRANIA_HH
#define GORA_Z_GRANIA_HH

#define WIERZCHOLKI 8

#include "BrylaGeometryczna.hh"
#include <iostream>                                                                                                                                                                                                                                                                                                                                         
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <cmath>

/*!
 *  \brief Definicja klasy Gora_z_grania.
 *
 * Klasa reprezentuje Gora_z_grania, obiekt skladajacy 
 * sie z 6 wierzcholkow. Wymiary Gory_z_grania mozna
 * ustawic za pomoca parametrow: dlugosc, szerokosc, wysokosc 
 * oraz wierzcholki zapisac do pliku. 
 */
class Gora_z_grania: public BrylaGeometryczna {
    
  public:
/*!
 * \brief Konstruktor bezparametryczny klasy Gora_z_grania
 */
    Gora_z_grania();
    
/*!
 * \brief Konstruktor parametryczny klasy Gora_z_grania
 */
    Gora_z_grania( Wektor3D srodek, double dlugosc, double szerokosc, double wysokosc, std::string sNazwaPliku);                                                                                                                                                                                                                                                                      

/*!
 * \brief Metoda odpowiada za zapis wspolrzednych do pliku
 */
    bool Zapis_do_pliku();
    
/*!
 * \brief Destruktor, usuwa wymiary drona
 */
    ~Gora_z_grania();
};
  
/*!
 * \brief Przeciazenie operatora wyswietlania.
 *
 * Przeciazenie sluzy do przekazywania do strumienia wspolrzednych
 * wierzcholkow Gory_z_grania.
 */
//wyswietla wspolrzedne wierzcholkow Gory_z_grania 
std::ostream& operator << ( std::ostream &Strm, const Gora_z_grania &grania); 


#endif

