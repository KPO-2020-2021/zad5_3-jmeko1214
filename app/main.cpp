// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.

/*!
 * \file
 * \brief Animacjia przelotu drona
 */
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <unistd.h>
#include <stdlib.h>

#include "lacze_do_gnuplota.hh"
#include "exampleConfig.h"
#include "example.h"
#include "Scena.hh"

using namespace std;


/*!
 * \brief Proste menu
 *
 * Wyswietla proste menu programu.
 */
void Menu_wyswietl()
{
  cout<<endl;
  cout<<" Menu programu:"<<endl<<endl;
  cout<<"  a - wybierz aktywnego drona"<<endl;
  cout<<"  p - zadaj parametry przelotu"<<endl;
  cout<<"  d - dodaj element powierzchni"<<endl;
  cout<<"  m - wyswietl menu"<<endl<<endl;
  cout<<"  k - koniec dzialania programu"<<endl;
  cout<<endl;
}


/*!
 * \brief Glowna petla programu
 *
 * Petla main, w ktorej jest zawarte wywolywanie poszczegolnych
 * funkcji programu. Zawiera proste menu obslugujace ruch drona.
 */
int main() {
  cout << " Project Dron based on C++ Boiler Plate v"
            << PROJECT_VERSION_MAJOR
            << "."
            << PROJECT_VERSION_MINOR
            << "."
            << PROJECT_VERSION_PATCH
            << "."
            << PROJECT_VERSION_TWEAK
            << endl << endl;
        
  PzG::LaczeDoGNUPlota  Lacze;  // Zmienna odpowiada za wizualizacje rysunku prostopadloscianu
  Lacze.ZmienTrybRys(PzG::TR_3D);
  
  Wektor3D wektor;
  Scena scena;
  char opcja=0;         //zmienna dla obslugi prostego menu

  cout<<" Program rysuje w gnuplocie Drona oraz przeszkody,"<<endl;
  cout<<" obraca drona o zadany kat i przesuwa o zadana droge."<<endl;
  cout<<" Wynik jest wyswietlany w gnuplocie oraz zapisywany do pliku."<<endl<<endl;
  
  wektor.Ilosc_wektorow();

  Menu_wyswietl();

  while(opcja!='k')
  {
    cout<<endl;
    cout<<" Twoj wybor, m - menu> ";
    cin>>opcja;
    cout<<endl;

    switch(opcja)   //obsluga prostego menu
    {
      case 'a':
      {
        scena.Wybor_drona();
        break;
      }
      case 'p':
      {
        scena.Ruch_dronem();
        break;
      }
      case 'd':
      {
        scena.Dodaj_przeszkode();
        break;
      }
      case 'm':
      {
        Menu_wyswietl(); 
        break;
      }
      case 'k':
      {
        cout<<"\n Koniec dzialania programu.\n"<<endl;
        break;
      }
      default:
      {
        cerr<<"\n Blad! Nie rozpoznano opcji menu. Sprobuj jeszcze raz."<<endl;
        break;
      }
    }
  }
  wektor.Ilosc_wektorow();

  // Bring in the dummy class from the example source,
  // just to show that it is accessible from main.cpp.
  Dummy d = Dummy();
  return d.doSomething() ? 0 : -1;
}


