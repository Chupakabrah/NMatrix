// Készítette: Molnár Máté
// Dátum:2021.03.05.
// Neptun kód: tjl3rx
// Csoport: 2.
// Feladat: N-mátrixtípus

#include "NMX.h"
#include <iostream>
#include <iomanip>

using namespace std;

NMX::NMX(int a)
{
    if(a == 0)
    {
        vector<int>(a,0).swap(_vec);
    }
    else if(a > 0)
    {
        vector<int>(a*3-2,0).swap(_vec);
    }
    else
    {
        throw NEGATIVSIZE;
    }
    _mSize = a;
}

NMX::NMX(const std::vector<int> &vec)
{
    _vec = vec;
    _mSize = int((_vec.size() + 2) / 3);
}

void NMX::reSize(int a)
{
    if(a == 0)
    {
        std::vector<int>(a,0).swap(_vec);
    }
    else if(a > 0)
    {
        std::vector<int>(a*3-2,0).swap(_vec);
    }
    else
    {
        throw NEGATIVSIZE;
    }
    _mSize = a;
}

NMX operator+(const NMX& x, const NMX& y)
{
    if(x._mSize != y._mSize)
        throw NMX::DIFFERENT;

    NMX z(x._mSize);

    for(unsigned i = 0; i < z._vec.size(); ++i)
    {
        z._vec[i] = x._vec[i] + y._vec[i];
    }

    return z;
}

NMX operator*(const NMX& x, const NMX& y)
{
    if(x._mSize != y._mSize)
        throw NMX::DIFFERENT;

    NMX z(x._mSize);

    for(unsigned i = 0; i < z._vec.size(); ++i)
    {
        z._vec[i] = x._vec[i] * y._vec[i];
    }

    return z;
}

int NMX::operator()(int i, int j) const
{
    if((i >= _mSize || i < 0) || (j >= _mSize || j < 0)) throw OVERINDEX;
    if(i == j)
    {
        return _vec[i];
    }
    else if(j == 0)
    {
        return _vec[i + _mSize - 1];
    }
    else if(j == (_mSize - 1))
    {
        return _vec[i + _mSize*2 - 1];
    }
    else
    {
        return 0;
    }
}

int& NMX::operator()(int i, int j)
{
    if((i >= _mSize || i < 0) || (j >= _mSize || j < 0)) throw OVERINDEX;
    if(i == j)
    {
        return _vec[i];
    }
    else if(j == 0)
    {
        return _vec[i + _mSize - 1];
    }
    else if(j == (_mSize - 1))
    {
        return _vec[i + _mSize*2 - 1];
    }
    else
    {
        throw NULLPART;
    }
}

ostream& operator<<(ostream& s, const NMX& x)
{
    for(unsigned i = 0; i < unsigned(x._mSize); ++i)
    {
        for(unsigned j = 0; j < unsigned(x._mSize); ++j)
        {
            s << setw(3) << x(i,j);
        }
        s << endl;
    }

    return s;
}


istream& operator>>(istream& s, NMX& x)
{
    unsigned mSize;
    s >> mSize;
    if(mSize == 0) throw NMX::NO_MATRIX;
    x.reSize(mSize);


    for(unsigned i = 0; i < mSize; ++i)
    {
        cout << "  M[" << i+1 << ", " << i+1 << "]= ";
        s >> x(i,i);
    }
    for(unsigned i = 1; i < mSize; ++i)
    {
        cout << "  M[" << i+1 << ", " << 1 << "]= ";
        s >> x(i,0);
    }
    for(unsigned i = 0; i < mSize - 1; ++i)
    {
        cout << "  M[" << i+1 << ", " << mSize << "]= ";
        s >> x(i,mSize - 1);
    }

    return s;
}
