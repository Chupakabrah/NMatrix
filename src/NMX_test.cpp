// Készítette: Molnár Máté
// Dátum:2021.03.05.
// Neptun kód: tjl3rx
// Csoport: 2.
// Feladat: N-mátrixtípus

#include "NMX_test.h"

std::istream& operator>>(std::istream& s, NMX_test& x)
{
    unsigned mSize;
    s >> mSize;
    if(mSize == 0) throw NMX::NO_MATRIX;
    x.reSize(mSize);


    for(unsigned i = 0; i < mSize; ++i)
    {
        s >> x(i,i);
    }
    for(unsigned i = 1; i < mSize; ++i)
    {
        s >> x(i,0);
    }

    for(unsigned i = 0; i < mSize - 1; ++i)
    {
        s >> x(i,mSize - 1);
    }
    return s;
}

NMX_test operator+(const NMX_test& x, const NMX_test& y)
{
    if(x._mSize != y._mSize) throw NMX_test::DIFFERENT;

    NMX_test z(x._mSize);

    for(unsigned i = 0; i < z._vec.size(); ++i)
    {
        z._vec[i] = x._vec[i] + y._vec[i];
    }

    return z;
}

NMX_test operator*(const NMX_test& x, const NMX_test& y)
{
    if(x._mSize != y._mSize) throw NMX_test::DIFFERENT;


    NMX_test z(x._mSize);

    for(unsigned i = 0; i < z._vec.size(); ++i)
    {
        z._vec[i] = x._vec[i] * y._vec[i];
    }

    return z;
}
