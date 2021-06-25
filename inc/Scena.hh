#ifndef SCENA_HH
#define SCENA_HH

#include "lacze_do_gnuplota.hh"
#include "Plaszczyzna.hh"
#include "Plaskowyz.hh"
#include "Gora_z_grania.hh"
#include "Gora_ostra.hh"
#include "Dron.hh"
#include "Prostopadloscian.hh"
#include <iostream>
#include <memory>
#include <list>


/*!
 * \brief  Klasa opisuje Scene.
 *
 *  Tutaj znajduje sie definicja klasy Scena.
 *  Tworzy scene, na ktorej dochodzi do ruchu drona.
 */
class Scena {
    private:
    PzG::LaczeDoGNUPlota Lacze;
    Plaszczyzna *dno;
    Dron *drony[2];     //tablica dronow
    int numer;          //numer drona
    std::list<std::shared_ptr<BrylaGeometryczna>> przeszkody;    //lista przeszkod

    public:
/*!
 * \brief Konstruktor klasy Scena
 */
    Scena();

/*!
 * \brief Metoda odpowiada za rysowanie
 */   
    void Rysuj();

/*!
 * \brief Metoda odpowiada za wybor Drona
 */
    bool Wybor_drona();

/*!
 * \brief Metoda odpowiada za ustawienie drona aktywnego
 */
    void Ruch_dronem();

/*!
 * \brief Metoda odpowiada za dodawanie przeszkod do sceny
 */
    void Dodaj_przeszkode();

/*!
 * \brief Destruktor, usuwa dno oraz drony
 */
    ~Scena();
};


#endif

