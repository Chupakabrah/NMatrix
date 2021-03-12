// Készítette: Molnár Máté
// Dátum:2021.03.05.
// Neptun kód: tjl3rx
// Csoport: 2.
// Feladat: N-mátrixtípus

#pragma once
#include <iostream>
#include <vector>

class NMX
{
public:
    enum Exceptions {NULLPART, DIFFERENT, OVERINDEX, NEGATIVSIZE, NO_MATRIX};

    NMX() {}
    explicit NMX(int a);
    explicit NMX(const std::vector<int> &vec);

    void reSize(int a);

    int operator()(int i, int j) const;
    int& operator()(int i, int j);

    friend NMX operator+ (const NMX& x, const NMX& y);
    friend NMX operator* (const NMX& x, const NMX& y);
    friend std::ostream& operator<< (std::ostream& s, const NMX& x);
    friend std::istream& operator>> (std::istream& s, NMX& x);

protected:
    std::vector<int> _vec;
    int _mSize;
};

