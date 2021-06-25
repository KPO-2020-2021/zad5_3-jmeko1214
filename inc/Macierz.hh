#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "size.hh"
#include "Wektor.hh"
#include <iostream>
#include <cstdlib>
#include <cmath>

/*!
 * \file
 * \brief Ten plik zawiera definicję szablonu klasy Macierz<>
 *
 * Ten plik zawiera definicję szablonu Macierz<>.
 * W tym celu przerobiono definicję klasy Macierz2x2.
 */


/*!
 * \brief  Szablon klasy macierz.
 *
 *  Szablon klasy reprezentuje macierz kwadratowa o zadanym rozmiarze.
 *  Na macierzy mozna wykonywac podstawowe dzialania matematyczne.
 */
template <int SIZE>
class Macierz
{
    double value[SIZE][SIZE];               // Wartosci macierzy
  
  public:
    Macierz<SIZE>(double [SIZE][SIZE]);            // Konstruktor klasy
    Macierz<SIZE>();                               // Konstruktor klasy
    //Przeciazenia operatorow
    Wektor<SIZE> operator * (Wektor<SIZE> tmp) const;           // Operator mnożenia przez wektor
    Macierz<SIZE> operator * (Macierz<SIZE> tmp);
    Macierz<SIZE> operator + (Macierz<SIZE> tmp);
    double  &operator () (unsigned int row, unsigned int column);
    const double &operator () (unsigned int row, unsigned int column) const;
    bool operator == (const Macierz<SIZE> &Macierz) const;
    bool operator != (const Macierz<SIZE> &Macierz) const;  
};

/*!
 * \brief Przeciążenie operatora wczytania.
 * 
 * Strumien wczytuje dane macierzy i je zapisuje.
 */
template <int SIZE>
inline
std::istream &operator>>(std::istream &Strm, Macierz<SIZE> &Mac);

/*!
 * \brief Przeciążenie operatora wypisania.
 * 
 * Strumien wypisuje zapisane dane macierzy.
 */
template <int SIZE>
inline
std::ostream& operator<<(std::ostream &Strm, const Macierz<SIZE> &Mac);

#include "Macierz.cpp"

#endif
