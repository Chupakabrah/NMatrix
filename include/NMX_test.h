// K�sz�tette: Moln�r M�t�
// D�tum:2021.03.05.
// Neptun k�d: tjl3rx
// Csoport: 2.
// Feladat: N-m�trixt�pus

#pragma once
#include "NMX.h"
#include <iostream>
#include <vector>

class NMX_test : public NMX
{
public:
    NMX_test() : NMX() {}
    explicit NMX_test(int a) : NMX(a) {}
    explicit NMX_test(const std::vector<int> &vec) : NMX(vec) {}
    friend std::istream& operator>> (std::istream& s, NMX_test& x);
    friend NMX_test operator+ (const NMX_test& x, const NMX_test& y);
    friend NMX_test operator* (const NMX_test& x, const NMX_test& y);
};

