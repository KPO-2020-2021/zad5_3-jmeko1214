#include "../tests/doctest/doctest.h"
#include "../inc/Macierz3x3.hh"
#include "../inc/Wektor3D.hh"

TEST_CASE("Test 1 operatora porownania '=='")
{
    Macierz3x3 A,B;
    A(0,0)=1; A(0,1)=2; A(0,2)=3;
    A(1,0)=4; A(1,1)=5; A(1,2)=6;
    A(2,0)=7; A(2,1)=8; A(2,2)=9;

    B(0,0)=1; B(0,1)=2; B(0,2)=3;
    B(1,0)=4; B(1,1)=5; B(1,2)=6;
    B(2,0)=7; B(2,1)=8; B(2,2)=9;

    CHECK(A==B);
}

TEST_CASE("Test 2 operatora porownania '=='")
{
    Macierz3x3 A,B;
    A(0,0)=1; A(0,1)=2; A(0,2)=3;
    A(1,0)=4; A(1,1)=5; A(1,2)=6;
    A(2,0)=7; A(2,1)=8; A(2,2)=9;

    B(0,0)=1; B(0,1)=2; B(0,2)=7;
    B(1,0)=5; B(1,1)=5; B(1,2)=6;
    B(2,0)=7; B(2,1)=8; B(2,2)=9;

    CHECK_FALSE(A==B);
}

TEST_CASE("Test 1 operatora porownania '!='")
{
    Macierz3x3 A,B;
    A(0,0)=1; A(0,1)=2; A(0,2)=3;
    A(1,0)=4; A(1,1)=5; A(1,2)=6;
    A(2,0)=7; A(2,1)=8; A(2,2)=9;

    B(0,0)=1; B(0,1)=2; B(0,2)=7;
    B(1,0)=5; B(1,1)=5; B(1,2)=6;
    B(2,0)=7; B(2,1)=8; B(2,2)=9;

    CHECK(A!=B);
}

TEST_CASE("Test 2 operatora porownania '!='")
{
    Macierz3x3 A,B;
    A(0,0)=1; A(0,1)=2; A(0,2)=3;
    A(1,0)=4; A(1,1)=5; A(1,2)=6;
    A(2,0)=7; A(2,1)=8; A(2,2)=9;

    B(0,0)=1; B(0,1)=2; B(0,2)=3;
    B(1,0)=4; B(1,1)=5; B(1,2)=6;
    B(2,0)=7; B(2,1)=8; B(2,2)=9;

    CHECK_FALSE(A!=B);
}

TEST_CASE("Test 1 operatora mnozenia")
{
    Wektor3D a,b;
    Macierz3x3 A;
    double wek1[3]={1,1,1}, wek2[3]={3,3,3};
    a=Wektor3D(wek1);
    b=Wektor3D(wek2);
    A(0,0)=1; A(0,1)=1; A(0,2)=1;
    A(1,0)=1; A(1,1)=1; A(1,2)=1;
    A(2,0)=1; A(2,1)=1; A(2,2)=1;

    CHECK((A*a)==b);
}

TEST_CASE("Test 2 operatora mnozenia")
{
    Wektor3D a,b;
    Macierz3x3 A;
    double wek1[3]={1,1,1}, wek2[3]={1,1,1};
    a=Wektor3D(wek1);
    b=Wektor3D(wek2);
    A(0,0)=1; A(0,1)=1; A(0,2)=1;
    A(1,0)=1; A(1,1)=1; A(1,2)=1;
    A(2,0)=1; A(2,1)=1; A(2,2)=1;

    CHECK_FALSE((A*a)==b);
}
