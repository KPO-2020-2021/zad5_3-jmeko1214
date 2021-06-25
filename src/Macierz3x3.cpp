#include "Macierz3x3.hh"


/*!
 * \brief Tutaj znajduje sie definicja metody klasy Macierz3x3.
 *
 * Metoda sluzy do generowania macierzy obrotu o zadany kat,
 * wokol wybranej osi.
 */
Macierz3x3 MacierzObrotu(double kat, char Os)
{
    Macierz3x3 Wynik;
    double radiany;
    radiany = kat*PI/180;       //zaimana katu na radiany

    switch(Os)
    {
        case 'x':
        {
            Wynik(0,0) = 1;
            Wynik(0,1) = 0;
            Wynik(0,2) = 0;
            Wynik(1,0) = 0;
            Wynik(1,1) = cos(radiany);
            Wynik(1,2) = -sin(radiany);
            Wynik(2,0) = 0;
            Wynik(2,1) = sin(radiany);
            Wynik(2,2) = cos(radiany);
            break;
        }
        case 'y':
        {
            Wynik(0,0) = cos(radiany);
            Wynik(0,1) = 0;
            Wynik(0,2) = sin(radiany);
            Wynik(1,0) = 0;
            Wynik(1,1) = 1;
            Wynik(1,2) = 0;
            Wynik(2,0) = -sin(radiany);
            Wynik(2,1) = 0;
            Wynik(2,2) = cos(radiany);
            break;
        }
        case 'z':
        {
            Wynik(0,0) = cos(radiany);
            Wynik(0,1) = -sin(radiany);
            Wynik(0,2) = 0;
            Wynik(1,0) = sin(radiany);
            Wynik(1,1) = cos(radiany);
            Wynik(1,2) = 0;
            Wynik(2,0) = 0;
            Wynik(2,1) = 0;
            Wynik(2,2) = 1;
            break;
        }
        default:
        {
            std::cerr<<"\n Blad: Nierozpoznano osi!"<<std::endl;
            break;
        }
    }
    return Wynik;
}
