// Készítette: Molnár Máté
// Dátum:2021.03.05.
// Neptun kód: tjl3rx
// Csoport: 2.
// Feladat: N-mátrixtípus

#include <iostream>
#include "Menu.h"

using namespace std;

#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{
    Menu m;
    m.run();

    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "NMX_test.h"

TEST_CASE("Letrehoz, feltolt", "test.txt")
{
    ifstream in("test.txt");
    REQUIRE(!in.fail());

    NMX_test x;
    in >> x; // 3
    CHECK(x(0,0) == 1);
    CHECK(x(1,1) == 2);
    CHECK(x(2,2) == 3);
    CHECK(x(1,0) == 4);
    CHECK(x(2,0) == 5);
    CHECK(x(0,2) == 6);
    CHECK(x(1,2) == 7);

    NMX_test y;
    in >> y; // 2
    CHECK(y(0,0) == 1);
    CHECK(y(1,1) == 2);
    CHECK(y(1,0) == 3);
    CHECK(y(0,1) == 4);

    NMX_test z;
    in >> z; // 1
    CHECK(y(0,0) == 1);
}

TEST_CASE("Leker - Felulir", "Ertekadas:Tomb")
{
    NMX_test x({1,2,3,4,5,6,7});
    CHECK(x(0,0) == 1);
    CHECK(x(1,0) == 4);
    CHECK(x(1,2) == 7);
    x(0,0) = 2;
    x(1,0) = 4;
    x(1,2) = 8;
    CHECK(x(0,0) == 2);
    CHECK(x(1,0) == 4);
    CHECK(x(1,2) == 8);
}

TEST_CASE("Vector - al valo ertekadas es txt input megegyezik", "Vector & test.txt")
{
    ifstream in("test.txt");
    REQUIRE(!in.fail());

    vector<int> a = {1,2,3,4,5,6,7};
    NMX_test x({1,2,3,4,5,6,7});
    NMX_test y;
    NMX_test z(a);
    in >> y;

    CHECK(x(0,0) == y(0,0));
    CHECK(x(1,1) == y(1,1));
    CHECK(x(2,2) == y(2,2));
    CHECK(x(1,0) == y(1,0));
    CHECK(x(2,0) == y(2,0));
    CHECK(x(0,2) == y(0,2));
    CHECK(x(1,2) == y(1,2));

    CHECK(z(0,0) == y(0,0));
    CHECK(z(1,1) == y(1,1));
    CHECK(z(2,2) == y(2,2));
    CHECK(z(1,0) == y(1,0));
    CHECK(z(2,0) == y(2,0));
    CHECK(z(0,2) == y(0,2));
    CHECK(z(1,2) == y(1,2));

}

TEST_CASE("Konstruktor masolasa", "(x=y):test.txt")
{
    ifstream in("test.txt");
    REQUIRE(!in.fail());

    NMX_test x;
    in >> x;
    NMX_test y = x;

    CHECK(x(0,0) == y(0,0));
    CHECK(x(1,1) == y(1,1));
    CHECK(x(2,2) == y(2,2));
    CHECK(x(1,0) == y(1,0));
    CHECK(x(2,0) == y(2,0));
    CHECK(x(0,2) == y(0,2));
    CHECK(x(1,2) == y(1,2));
}

TEST_CASE("Ertekadas operator", "op= & test.txt")
{
    ifstream in("test.txt");
    REQUIRE(!in.fail());

    NMX_test x, y;
    in >> x;

    y = x;
    CHECK(x(0,0) == y(0,0));
    CHECK(x(1,1) == y(1,1));
    CHECK(x(2,2) == y(2,2));
    CHECK(x(1,0) == y(1,0));
    CHECK(x(2,0) == y(2,0));
    CHECK(x(0,2) == y(0,2));
    CHECK(x(1,2) == y(1,2));

    NMX_test z;

    z = y = x;
    CHECK(x(0,0) == z(0,0));
    CHECK(x(1,1) == z(1,1));
    CHECK(x(2,2) == z(2,2));
    CHECK(x(1,0) == z(1,0));
    CHECK(x(2,0) == z(2,0));
    CHECK(x(0,2) == z(0,2));
    CHECK(x(1,2) == z(1,2));

    x = x;
    CHECK(x(0,0) == 1);
    CHECK(x(1,1) == 2);
    CHECK(x(2,2) == 3);
    CHECK(x(1,0) == 4);
    CHECK(x(2,0) == 5);
    CHECK(x(0,2) == 6);
    CHECK(x(1,2) == 7);
}

TEST_CASE("Osszeadas", "op+ & test2.txt")
{
    ifstream in("test2.txt");
    REQUIRE(!in.fail());

    NMX_test x, y, z, q;
    NMX_test e, f, g, h, i;
    in >> x >> y >> z >> q;

    e = x + q;
    CHECK(e(0,0) == -6);
    CHECK(e(1,1) == -4);
    CHECK(e(2,2) == -2);
    CHECK(e(1,0) == 0);
    CHECK(e(2,0) == 2);
    CHECK(e(0,2) == 4);
    CHECK(e(1,2) == 6);

    f = q + x;
    CHECK(f(0,0) == -6);
    CHECK(f(1,1) == -4);
    CHECK(f(2,2) == -2);
    CHECK(f(1,0) == 0);
    CHECK(f(2,0) == 2);
    CHECK(f(0,2) == 4);
    CHECK(f(1,2) == 6);

    g = (x + q) + y;
    h = x + (q + y);
    CHECK(g(0,0) == h(0,0));
    CHECK(g(1,1) == h(1,1));
    CHECK(g(2,2) == h(2,2));
    CHECK(g(1,0) == h(1,0));
    CHECK(g(2,0) == h(2,0));
    CHECK(g(0,2) == h(0,2));
    CHECK(g(1,2) == h(1,2));

    i = x + z;
    CHECK(i(0,0) == x(0,0));
    CHECK(i(1,1) == x(1,1));
    CHECK(i(2,2) == x(2,2));
    CHECK(i(1,0) == x(1,0));
    CHECK(i(2,0) == x(2,0));
    CHECK(i(0,2) == x(0,2));
    CHECK(i(1,2) == x(1,2));
}

TEST_CASE("Szorzas", "op* = test2.txt")
{
    ifstream in("test2.txt");
    REQUIRE(!in.fail());

    NMX_test x, y, z, q;
    NMX_test e, f, g, h, i;
    in >> x >> y >> z >> q;

    e = x * y;
    CHECK(e(0,0) == 7);
    CHECK(e(1,1) == 12);
    CHECK(e(2,2) == 15);
    CHECK(e(1,0) == 16);
    CHECK(e(2,0) == 15);
    CHECK(e(0,2) == 12);
    CHECK(e(1,2) == 7);

    f = y * x;
    CHECK(e(0,0) == f(0,0));
    CHECK(e(1,1) == f(1,1));
    CHECK(e(2,2) == f(2,2));
    CHECK(e(1,0) == f(1,0));
    CHECK(e(2,0) == f(2,0));
    CHECK(e(0,2) == f(0,2));
    CHECK(e(1,2) == f(1,2));

    g = (x * y) * q;
    h = x * (y * q);
    CHECK(g(0,0) == h(0,0));
    CHECK(g(1,1) == h(1,1));
    CHECK(g(2,2) == h(2,2));
    CHECK(g(1,0) == h(1,0));
    CHECK(g(2,0) == h(2,0));
    CHECK(g(0,2) == h(0,2));
    CHECK(g(1,2) == h(1,2));

    i = x * z;
    CHECK(z(0,0) == i(0,0));
    CHECK(z(1,1) == i(1,1));
    CHECK(z(2,2) == i(2,2));
    CHECK(z(1,0) == i(1,0));
    CHECK(z(2,0) == i(2,0));
    CHECK(z(0,2) == i(0,2));
    CHECK(z(1,2) == i(1,2));
}

TEST_CASE("Kivetel_index", "OVERINDEX")
{
    NMX_test x(3);
    try
    {
        x(3,3) = 5;
    }
    catch(NMX_test::Exceptions ex)
    {
        CHECK(ex == NMX_test::OVERINDEX);
    }
    try
    {
        x(-1,4) = 2;
    }
    catch(NMX_test::Exceptions ex)
    {
        CHECK(ex == NMX_test::OVERINDEX);
    }
}

TEST_CASE("Kivetel_meret", "DIFFERENT")
{
    NMX_test x(3);
    NMX_test y(2);
    NMX_test z(3);
    try
    {
        x = y;
    }
    catch(NMX_test::Exceptions ex)
    {
        CHECK(ex == NMX_test::DIFFERENT);
    }

    try
    {
        z = y + x;
    }
    catch(NMX_test::Exceptions ex)
    {
        CHECK(ex == NMX_test::DIFFERENT);
    }

    try
    {
        z = x * y;
    }
    catch(NMX_test::Exceptions ex)
    {
        CHECK(ex == NMX_test::DIFFERENT);
    }
}

TEST_CASE("Kivetel_nulla", "NULLPART")
{
    NMX_test x(3);
    try
    {
        x(0,1) = 3;
    }
    catch(NMX_test::Exceptions ex)
    {
        CHECK(ex == NMX_test::NULLPART);
    }

    try
    {
        x(2,1) = 2;
    }
    catch(NMX_test::Exceptions ex)
    {
        CHECK(ex == NMX_test::NULLPART);
    }
}

TEST_CASE("Kivetel_negativmeret", "NEGATIVSIZE")
{
    try
    {
        NMX_test k(-1);
    }
    catch(NMX_test::Exceptions ex)
    {
        CHECK(ex == NMX_test::NEGATIVSIZE);
    }
}

TEST_CASE("Kivetel_nullameret", "NO_MATRIX")
{
    try
    {
        NMX_test x(0);
    }
    catch(NMX_test::Exceptions ex)
    {
        CHECK(ex == NMX_test::NO_MATRIX);
    }
}

#endif // NORMAL_MODE
