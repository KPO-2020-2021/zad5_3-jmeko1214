#ifndef PLASZCZYZNA_HH
#define PLASZCZYZNA_HH

#include "BrylaGeometryczna.hh"
#include "Wektor3D.hh"
#include "Macierz3x3.hh"


/*!
 * \brief  Klasa opisuje Plaszczyzne.
 *
 *  Tutaj znajduje sie definicja klasy Plaszczyzna.
 *  Tworzy powierzchnie Marsa
 */
class Plaszczyzna {
    protected:
    std::vector<Wektor3D> siatka;
    std::string sNazwaPliku;
    int ilosc;

    public:
/*!
 * \brief Konstruktor parametryczny klasy Plaszczyzna
 */
    Plaszczyzna(double dlugosc, double szerokosc, double wysokosc, std::string sNazwaPliku);
    
/*!
 * \brief Metoda odpowiada za zapis wspolrzednych do pliku
 */
    bool Zapisz_do_pliku();
};


#endif

