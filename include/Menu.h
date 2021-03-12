// K�sz�tette: Moln�r M�t�
// D�tum:2021.03.05.
// Neptun k�d: tjl3rx
// Csoport: 2.
// Feladat: N-m�trixt�pus

#pragma once
#include <iostream>
#include "NMX.h"

//Men� az N-m�trixt�pus kezel�s�hez

class Menu
{
public:
    Menu() : _x(0) {}
    void run();
private:
    NMX _x;
    void showMenu();
    void getElement() const;
    void setElement();
    void readMatrix();
    void showMatrix();
    void sum();
    void mul();
};
