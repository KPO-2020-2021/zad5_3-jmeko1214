#ifndef GRANIASTOSLUP6_HH
#define GRANIASTOSLUP6_HH

#define GRANIA_SIZE 12

#include "BrylaGeometryczna.hh"
#include <vector>


class Graniastoslup6: public BrylaGeometryczna {
    public:
    Graniastoslup6();
    Graniastoslup6(Wektor3D srodek, double promien, std::string sNazwaPliku);
    
    
    ~Graniastoslup6();
};





#endif

