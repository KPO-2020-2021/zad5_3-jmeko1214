#include "../tests/doctest/doctest.h"
#include "../inc/Wektor.hh"
#include "../inc/Wektor3D.hh"



TEST_CASE("Test konstruktora bezparametrycznego")
{
    Wektor3D a;
    CHECK(a[0]==0);
    CHECK(a[1]==0);
    CHECK(a[2]==0);
}

TEST_CASE("Test konstruktora z parametrem")
{
    Wektor3D a;
    double wek[3]={1,1,1};
    a=Wektor3D(wek);
    CHECK(a[0]==1);
    CHECK(a[1]==1);
    CHECK(a[2]==1);
}

TEST_CASE("Test 1. Przeciazenie operatora porownania '==' ")
{
    Wektor3D a,b,c;
    double wek1[3]={1,1,1},wek2[3]={1,1,1},wek3[3]={1,0,1};
    a=Wektor3D(wek1);
    b=Wektor3D(wek2);
    c=Wektor3D(wek3);
    CHECK(a==b);
    CHECK_FALSE(a==c);
}

TEST_CASE("Test 2. Przeciazenie operatora porownania '==' ")
{
    Wektor3D a,b,c;
    double wek1[3]={1.00000000001,1.00000000001,1},wek2[3]={1,1,1},wek3[3]={1,0,1};
    a=Wektor3D(wek1);
    b=Wektor3D(wek2);
    c=Wektor3D(wek3);
    CHECK(a==b);
    CHECK_FALSE(a==c);
}

TEST_CASE("Test 1. Przeciazenie operatora porownania '!=' ")
{
    Wektor3D a,b,c;
    double wek1[3]={1,1,1},wek2[3]={1,1,1},wek3[3]={1,0,1};
    a=Wektor3D(wek1);
    b=Wektor3D(wek2);
    c=Wektor3D(wek3);
    CHECK(a!=c);
    CHECK_FALSE(a!=b);
}

TEST_CASE("Test 2. Przeciazenie operatora porownania '!=' ")
{
    Wektor3D a,b,c;
    double wek1[3]={1.00000000001,1.00000000001,1},wek2[3]={1,1,1},wek3[3]={1,0,1};
    a=Wektor3D(wek1);
    b=Wektor3D(wek2);
    c=Wektor3D(wek3);
    CHECK(a!=c);
    CHECK_FALSE(a!=b);
}

TEST_CASE("Test 1: Przeciazenie operatora dodawania")
{
    Wektor3D a,b,c,d;
    double wek1[3]={4,2,0},wek2[3]={2,2,2},wek3[3]={6,4,2},wek4[3]={4,4,4};
    a=Wektor3D(wek1);
    b=Wektor3D(wek2);
    c=Wektor3D(wek3);
    d=Wektor3D(wek4);
    CHECK(a+b==c);
    CHECK_FALSE(a+b==d);
}

TEST_CASE("Test 2: Przeciazenie operatora dodawania - dokladnosc")
{
    Wektor3D a,b,c,d;
    double wek1[3]={4.0000000001,2.0000000001,1},wek2[3]={2,2,1},wek3[3]={6.0000000001,4.0000000001,2},wek4[3]={4,0,2};
    a=Wektor3D(wek1);
    b=Wektor3D(wek2);
    c=Wektor3D(wek3);
    d=Wektor3D(wek4);
    CHECK(a+b==c);
    CHECK_FALSE(a+b==d);
}

TEST_CASE("Test 1: Przeciazenie operatora odejmowania")
{
    Wektor3D a,b,c,d;
    double wek1[3]={4,2,2},wek2[3]={2,2,0},wek3[3]={2,0,2},wek4[3]={4,4,0};
    a=Wektor3D(wek1);
    b=Wektor3D(wek2);
    c=Wektor3D(wek3);
    d=Wektor3D(wek4);
    CHECK(a-b==c);
    CHECK_FALSE(a-b==d);
}

TEST_CASE("Test 2: Przeciazenie operatora odejmowania - dokladnosc")
{
    Wektor3D a,b,c,d;
    double wek1[3]={4.0000000001,2.0000000001,2},wek2[3]={2,2,1},wek3[3]={2.0000000001,0.0000000001,1},wek4[3]={4,0,2};
    a=Wektor3D(wek1);
    b=Wektor3D(wek2);
    c=Wektor3D(wek3);
    d=Wektor3D(wek4);
    CHECK(a-b==c);
    CHECK_FALSE(a-b==d);
}

TEST_CASE("Test operatora []")
{
    Wektor3D x,y,z;
    double wek1[3]={1,2,3},wek2[3]={4,5,6},wek3[3]={7,8,9};
    x=Wektor3D(wek1);
    y=Wektor3D(wek2);
    z=Wektor3D(wek3);
    double x1,x2,x3,y1,y2,y3,z1,z2,z3;
    x1=1; y1=4; z1=7;
    x2=2; y2=5; z2=8;
    x3=3; y3=6; z3=9;

    CHECK(x1==x[0]);
    CHECK(x2==x[1]);
    CHECK(x3==x[2]);
    CHECK(y1==y[0]);
    CHECK(y2==y[1]);
    CHECK(y3==y[2]);
    CHECK(z1==z[0]);
    CHECK(z2==z[1]);
    CHECK(z3==z[2]);
}


