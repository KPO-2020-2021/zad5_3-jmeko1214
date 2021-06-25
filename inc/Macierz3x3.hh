#ifndef MACIERZ3X3_HH
#define MACIERZ3X3_HH

#define PI 3.1415926535

#include <iostream>

#include "Macierz.hh"

/*!
 * \brief Klasa Macierz3x3 jest instancją szablonu Macierz<>
 *
 *  Klasa reprezentuje macierz kwadratowa o zadanym rozmiarze 3.
 *  Na macierzy mozna wykonywac proste operacje matematyczne
 *  z dzialan z arytmetyki na macierzach, oraz pozwala je wczytac
 *  oraz wyswietlac.
 */
typedef Macierz<3>  Macierz3x3;

/*!
 * \brief Metoda klasy Macierz3x3.
 *
 *  Metoda sluzy do generowania macierzy obrotu o zadany kat,
 *  wokol wybranej osi.
 */
Macierz3x3 MacierzObrotu(double kat, char Os);

#endif
