#include "Plaszczyzna.hh"


/******************************************************************************
 |  Konstruktor parametryczny klasy Plaszczyzna.                              |
 |  Argumenty:                                                                |
 |     dlugosc - dlugosc plaszczyzny                                          |
 |     szerokosc - szerokosc plaszczyzny                                      |
 |     wysokosc - wysokosc plaszczyzny                                        |
 |     sNazwaPliku - przechowuje nazwe pliku zawierajacego wspolrzedne        |
 */
Plaszczyzna::Plaszczyzna(double dlugosc, double szerokosc, double wysokosc, std::string sNazwaPliku)
{
    this->sNazwaPliku = sNazwaPliku;
    Wektor3D wek;
    ilosc = 0;
    for(int i=-dlugosc/2; i<=dlugosc/2; i+=20)
    {
        for(int j=-szerokosc/2; j<=szerokosc/2; j+=20)
        {
            wek[0] = i;
            wek[1] = j;
            wek[2] = wysokosc;
            siatka.push_back(wek);
        }
        ilosc++;
    }
}

/******************************************************************************
 |  Realizuje zapis wspolrzednych Plaszczyzna do pliku                        |                                               
 |  Argumenty:                                                                |
 |     sNazwaPliku - nazwa pliku, do ktorego sa zapisywane wspolrzedne        |
 |                   plaszczyzny                                              |
 |  Zwraca:                                                                   |
 |     True lub False                                                         |
 */
bool Plaszczyzna::Zapisz_do_pliku()
{
    std::ofstream StrmPlikowy;

    StrmPlikowy.open(sNazwaPliku, std::ios::out);
    if(!StrmPlikowy.is_open())
    {
        std::cerr << ":( Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
                  << ":( nie powiodla sie." << std::endl;
        return false;
    }
    for(int i=0; i<(int)siatka.size(); i++)
    {
        if(i%ilosc==0)
        {
            StrmPlikowy << std::endl;
        }
        StrmPlikowy << siatka[i] << std::endl;
    }
    StrmPlikowy.close();
    return !StrmPlikowy.fail();

}
