#ifndef DRON_HH
#define DRON_HH

#include "Prostopadloscian.hh"
#include "Graniastoslup6.hh"
#include "BrylaGeometryczna.hh"
#include "lacze_do_gnuplota.hh"
#include <string.h>
#include <cmath>
#include <unistd.h>

#define CZEKAJ 5000

class Dron {
    private:
    PzG::LaczeDoGNUPlota &Lacze;
    Prostopadloscian *korpus;
    Wektor3D droga;
    Macierz3x3 obrot;
    double promien;         //przechowuje promien drona
    double wymiary[2];      //przechowuje wymiery x,y drona
    double wspolrzedne[2];  //przechowuje wspolrzedne drona po dokonaniu ruchu
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
    void Przesuniecie(double przesun, double kat);
    
    /*!
    * \brief Metoda odpowiada za rysowanie trasy Drona
    */
    void Trasa(double kat, double droga);

    /*!
    * \brief Metoda odpowiada za zwrocenie wsporzednej X aktywnego Drona
    */
    double Wspolrzedna_X();

    /*!
    * \brief Metoda odpowiada za zwrocenie wsporzednej Y aktywnego Drona
    */
    double Wspolrzedna_Y();

    /*!
    * \brief Metoda odpowiada za wyliczenie promienia Drona
    */
    double Promien_drona();
    
    /*!
    * \brief Metoda odpowiada za zapis wspolrzednych Drona do pliku
    */
    void Zapisz_do_pliku(); 
};



#endif

