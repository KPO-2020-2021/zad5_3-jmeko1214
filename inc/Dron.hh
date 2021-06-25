#ifndef DRON_HH
#define DRON_HH

#include "Prostopadloscian.hh"
#include "Graniastoslup6.hh"
#include "BrylaGeometryczna.hh"
#include "lacze_do_gnuplota.hh"
#include <string.h>
#include <unistd.h>

#define CZEKAJ 5000

class Dron {
    private:
    PzG::LaczeDoGNUPlota &Lacze;
    Prostopadloscian *korpus;
    Wektor3D droga;
    Macierz3x3 obrot;
    double kat;
    int id;
    char os;

    public:
    /*!
    * \brief Konstruktor bezparametryczny klasy Dron
    */
    Dron();
    
    /*!
    * \brief Konstruktor parametryczny klasy Dron
    */
    Dron(int id, PzG::LaczeDoGNUPlota &Lacze, Wektor3D polozenie);

    /*!
    * \brief Metoda odpowiada za lot w gore
    */
    void Lot_w_gore(double droga);
    
    /*!
    * \brief Metoda odpowiada za lot w dol
    */
    void Lot_w_dol(double droga);
    
    /*!
    * \brief Metoda odpowiada za obrot Drona
    */
    void Obrot(double kat);
    
    /*!
    * \brief Metoda odpowiada za przesuniecie Drona
    */
    void Przesuniecie(double przesun);
    
    /*!
    * \brief Metoda odpowiada za ruch Drona
    */
    void Steruj_dronem();
    
    /*!
    * \brief Metoda odpowiada za rysowanie trasy Drona
    */
    void Trasa(double kat, double droga);
    
    /*!
    * \brief Metoda odpowiada za zapis wspolrzednych Drona do pliku
    */
    void Zapisz_do_pliku(); 
};



#endif

