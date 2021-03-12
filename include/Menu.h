// Készítette: Molnár Máté
// Dátum:2021.03.05.
// Neptun kód: tjl3rx
// Csoport: 2.
// Feladat: N-mátrixtípus

#pragma once
#include <iostream>
#include "NMX.h"

//Menü az N-mátrixtípus kezeléséhez

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
