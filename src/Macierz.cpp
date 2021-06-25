#include "Macierz.hh"
#include <iostream>
#include <iomanip>
#include <cmath>


/******************************************************************************
 |  Konstruktor klasy Macierz.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelniona wartoscia 0.                                       |
 */
template <int SIZE>
Macierz<SIZE>::Macierz() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = 0;
        }
    }
}

/******************************************************************************
 |  Konstruktor parametryczny klasy Macierz.                                   |
 |  Argumenty:                                                                |
 |      tmp - dwuwymiarowa tablica z elementami typu double.                  |
 |  Zwraca:                                                                   |
 |      Macierz wypelniona wartosciami podanymi w argumencie.                 |
 */
template <int SIZE>
Macierz<SIZE>::Macierz(double tmp[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = tmp[i][j];
        }
    }
}

/******************************************************************************
 |  Realizuje mnozenie macierzy przez wektor.                                 |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik mnozenia,                     |
 |      v - wektor, czyli drugi skladnik mnozenia.                            |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */
template <int SIZE>
Wektor<SIZE> Macierz<SIZE>::operator * (Wektor<SIZE> tmp) const {
    Wektor<SIZE> result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}

/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy.                             |
 */
template <int SIZE>
double &Macierz<SIZE>::operator()(unsigned int row, unsigned int column) {

    if (row >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem"; 
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}

/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy jako stala.                  |
 */
template <int SIZE>
const double &Macierz<SIZE>::operator () (unsigned int row, unsigned int column) const {

    if (row >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}

/******************************************************************************
 |  Przeciążenie dodawania macierzy                                           |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik dodawania,                    |
 |      v - wektor, czyli drugi skladnik dodawania.                           |
 |  Zwraca:                                                                   |
 |      Macierz - iloczyn dwóch podanych macierzy.                            |
 */
template <int SIZE>
Macierz<SIZE> Macierz<SIZE>::operator + (Macierz<SIZE> tmp) {
    Macierz<SIZE> result;
    for (int i = 0; i < SIZE; ++i) 
    {
        for (int j = 0; j < SIZE; ++j) 
        {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}

/******************************************************************************
 |  Przeciążenie mnozenia macierzy                                           |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik dodawania,                    |
 |      v - wektor, czyli drugi skladnik dodawania.                           |
 |  Zwraca:                                                                   |
 |      Macierz - iloczyn dwóch podanych macierzy.                            |
 */
template <int SIZE>
Macierz<SIZE> Macierz<SIZE>::operator * (Macierz<SIZE> tmp) {
    Macierz<SIZE> result;
    for (int i = 0; i < SIZE; ++i) 
    {
        for (int j = 0; j < SIZE; ++j) 
        {
            result(i,j)=0;
            for(int k = 0; k < SIZE; ++k)
            {
                result(i,j) += this->value[i][k] * tmp(k, j);
            }
        }
    }
    return result;
}

/******************************************************************************
 |  Przeciazenie operatora porowanania ==.                                    |
 |  Argumenty:                                                                |
 |      Macierz i wskaźnik na Macierz.                                        |
 |  Zwraca:                                                                   |
 |      Wartość True lub False.                                               |
 */
template <int SIZE>
bool Macierz<SIZE>::operator == (const Macierz<SIZE> &Macierz) const
{
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            if(this->value[i][j] != Macierz.value[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

/******************************************************************************
 |  Przeciazenie operatora porowanania !=.                                    |
 |  Argumenty:                                                                |
 |      Macierz i wskaźnik na Macierz.                                        |
 |  Zwraca:                                                                   |
 |      Wartość True lub False.                                               |
 */
template <int SIZE>
bool Macierz<SIZE>::operator != (const Macierz<SIZE> &Macierz) const
{
    if(*this == Macierz)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      Strm - strumien wyjsciowy,                                            |
 |      Mac - macierz.                                                        |
 */
template <int SIZE>
std::istream &operator>>(std::istream &Strm, Macierz<SIZE> &Mac) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            Strm >> Mac(i, j);
        }
    }
    return Strm;
}

/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      Strm - strumien wejsciowy,                                            |
 |      Mac - macierz.                                                        |
 */
template <int SIZE>
std::ostream &operator<<(std::ostream &Strm, const Macierz<SIZE> &Mac) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            Strm << "| " << std::setw(15) << std::fixed << std::setprecision(10) << Mac(i, j) << " | "; //wyswietlanie macierzy
        }
        std::cout << std::endl;
    }
    return Strm;
}




