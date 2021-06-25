#include "Wektor.hh"
#include <iostream>
#include <iomanip>
#include <cmath>


/******************************************************************************
 |  Przeciazenie operatora porowanania ==.                                    |
 |  Argumenty:                                                                |
 |      Wektor i wskaźnik na wektor.                                          |
 |  Zwraca:                                                                   |
 |      Wartość True lub False.                                               |
 */
template <int SIZE>
bool Wektor<SIZE>::operator == (const Wektor<SIZE> &wek) const
{
    if(abs(size[0]-wek[0])<=MIN_DIFF && abs(size[1]-wek[1])<=MIN_DIFF)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/******************************************************************************
 |  Przeciazenie operatora porowanania !=.                                    |
 |  Argumenty:                                                                |
 |      Wektor i wskaźnik na wektor.                                          |
 |  Zwraca:                                                                   |
 |      Wartość True lub False.                                               |
 */
template <int SIZE>
bool Wektor<SIZE>::operator != (const Wektor<SIZE> &wek) const
{
    if(*this == wek)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/******************************************************************************
 |  Konstruktor klasy Wektor.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartoscia 0.                                       |
 */
template <int SIZE>
Wektor<SIZE>::Wektor() {
    for (int i = 0; i < SIZE; ++i) {
        size[i] = 0;
    }
    ilosc_obecnie++;
    ilosc_wszystkie++;
}


/******************************************************************************
 |  Konstruktor klasy Wektor.                                                 |
 |  Argumenty:                                                                |
 |      tmp - Jednowymiarowa tablica typu double.                             |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartosciami podanymi w argumencie.                 |
 */
template <int SIZE>
Wektor<SIZE>::Wektor(double tmp[SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        size[i] = tmp[i];
    }
    ilosc_obecnie++;
    ilosc_wszystkie++;
}

/******************************************************************************
 |  Konstruktor klasy Wektor.                                                 |
 |  Argumenty:                                                                |
 |      brak                                                                  |
 |  Zwraca:                                                                   |
 |      Ilosc aktualnych oraz ilosc wszystkich wektorow                       |
 */
template <int SIZE>
void Wektor<SIZE>::Ilosc_wektorow()
{
    std::cout << "   Aktualna ilosc obiektow Wektor3D: " << ilosc_obecnie << std::endl;
    std::cout << "     Laczna ilosc obiektow Wektor3D: " << ilosc_wszystkie << std::endl;
    std::cout << std::endl;
}


/******************************************************************************
 |  Metoda klasy Wektor.                                                      |
 |  Argumenty:                                                                |
 |     tmp - zmienna pomocnicza do liczenia modulu                            |
 |  Zwraca:                                                                   |
 |     mod - wartosc modulu                                                   |
 */
template <int SIZE>
double Wektor<SIZE>::modul() const
{
    double tmp=0;
    double mod=0;
    for(int i=0; i<SIZE; i++)
    {
        tmp = tmp + pow(size[i], 2);
    }
    mod = sqrt(tmp);
    return mod;
}

/******************************************************************************
 |  Realizuje dodawanie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik dodawania,                                   |
 |      v - drugi skladnik dodawania.                                         |
 |  Zwraca:                                                                   |
 |      Sume dwoch skladnikow przekazanych jako wskaznik                      |
 |      na parametr.                                                          |
 */
template <int SIZE>
Wektor<SIZE> Wektor<SIZE>::operator + (const Wektor<SIZE> &v) const {
    Wektor<SIZE> result;
    for (int i = 0; i < SIZE; ++i) {
        result[i] = this->size[i] + v[i];
    }
    return result;
}


/******************************************************************************
 |  Realizuje odejmowanie dwoch wektorow.                                     |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik odejmowania,                                 |
 |      v - drugi skladnik odejmowania.                                       |
 |  Zwraca:                                                                   |
 |      Roznice dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
template <int SIZE>
Wektor<SIZE> Wektor<SIZE>::operator - (const Wektor<SIZE> &v) const {
    Wektor<SIZE> result;
    for (int i = 0; i < SIZE; ++i) {
        result[i] = this->size[i] - v[i];
    }
    return result;
}


/******************************************************************************
 |  Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa.               |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik mnozenia (wektor),                           |
 |      v - drugi skladnik mnozenia (liczba typu double).                     |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
template <int SIZE>
Wektor<SIZE> Wektor<SIZE>::operator * (const double &tmp) {
    Wektor<SIZE> result;
    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] *= tmp;
    }
    return result;
}


/******************************************************************************
 |  Realizuje dzielenie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - licznik dzielenia,                                             |
 |      v - mianownik dzielenia.                                              |
 |  Zwraca:                                                                   |
 |      Iloraz dwoch skladnikow przekazanych jako wskaznik                    |
 |      na parametr.                                                          |
 */
template <int SIZE>
Wektor<SIZE> Wektor<SIZE>::operator / (const double &tmp) {
    Wektor<SIZE> result;
    if(tmp==0)
    {
        std::cerr<<"Blad! Nie mozna dzielic przez zero!"<<std::endl;
    }
    else
    {
        for (int i = 0; i < SIZE; ++i) 
        {
            result[i] = size[i] / tmp;
        }
    }
    return result;
}


/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy jako stala.                   |
 */
template <int SIZE>
const double &Wektor<SIZE>::operator [] (int index) const {
    if (index < 0 || index >= SIZE) {
        std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
    } // lepiej byłoby rzucić wyjątkiem stdexcept
    return size[index];
}


/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy.                              |
 */
template <int SIZE>
double &Wektor<SIZE>::operator[](int index) {
    return const_cast<double &>(const_cast<const Wektor<SIZE> *>(this)->operator[](index));
} 


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      Strm - strumien wejsciowy,                                             |
 |      Wek - wektor.                                                         |
 */
template <int SIZE>
std::ostream &operator << (std::ostream &Strm, Wektor<SIZE> const &Wek) {
    for (int i = 0; i < SIZE; ++i) 
    {
        Strm <<"\t"<<std::setprecision(10)<<std::fixed<<Wek[i] << "\t";
    }
    return Strm;
}


/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      Strm - strumien wyjsciowy,                                              |
 |      Wek - wektor.                                                         |
 */
template <int SIZE>
std::istream &operator >> (std::istream &Strm, Wektor<SIZE> &Wek) {
    for (int i = 0; i < SIZE; ++i) 
    {
        Strm >> Wek[i];
    }
    std::cout << std::endl;
    return Strm;
}

template <int SIZE>
Wektor<SIZE>::~Wektor()
{
    ilosc_obecnie--;
}


