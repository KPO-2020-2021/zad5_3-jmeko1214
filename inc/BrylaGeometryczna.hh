#ifndef BRYLAGEOMETRYCZNA_HH
#define BRYLAGEOMETRYCZNA_HH

#include "Macierz3x3.hh"
#include "Wektor3D.hh"
#include "Macierz.hh"
#include "size.hh"
#include <fstream>
#include <vector>

#define WIERZCHOLKI 8

/*!
 * \brief Klasa opisuje bryle geometryczna
 *
 * Klasa definiuje pojecie bryly geometrycznej,
 * zawiera metody potrzebne do opisu bryl, ktore
 * tworza drona: prostopadloscian i graniastoslup
 */ 
class BrylaGeometryczna{
    protected:
    Wektor3D srodek;
    Wektor3D *wymiary;
    std::vector<Wektor3D> wierzcholki;
    std::string sNazwaPliku;

    public:
/*!
 * \brief Przeciazenie operatora indeksowania, sluzy do odczytu i zapisu wierzcholkow
 */
    Wektor3D & operator[] (unsigned int index);
    
/*!
 * \brief Przeciazenie operatora indeksowania, sluzy do odczytu i zapisu wierzcholkow
 */    
    const Wektor3D & operator[] (unsigned int index) const;
    
/*!
 * \brief Metoda zwraca srodek bryly
 */    
    Wektor3D zwroc_srodek() const;
    
/*!
 * \brief Metoda zwraca nazwe pliku
 */    
    std::string ZwrocNazwaPliku() const;
    
/*!
 * \brief Metoda odpowiada za dodanie wektora przesuniecia
 */
    BrylaGeometryczna operator + (Wektor3D przesun);
    
/*!
 * \brief Metoda obraca bryle
 */
    void Obrot(Macierz3x3 macierz);
    
/*!
 * \brief Metoda przesuwa bryle o zadany wektor
 */    
    void Przesuniecie(Wektor3D przesun);
    
/*!
 * \brief Metoda zapisuje wspolrzedne wierzcholkow do pliku
 */
    bool Zapisz_do_pliku();
    
/*!
 * \brief Destruktor klasy BrylaGeometryczna
 */    
    ~BrylaGeometryczna();
};




#endif

