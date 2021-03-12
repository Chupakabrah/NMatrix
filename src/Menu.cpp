// Készítette: Molnár Máté
// Dátum:2021.03.05.
// Neptun kód: tjl3rx
// Csoport: 2.
// Feladat: N-mátrixtípus

#include "Menu.h"
#include <iomanip>

using namespace std;

void Menu::run()
{
    int n = 0;
    do
    {
        showMenu();
        cout << "  Menupont: ";
        cin >> n;

        while(cin.fail() || (n < 0 || n > 6))
        {
            cout << "  Menupont: ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> n;
        }
        cout << endl;

        switch(n)
        {
        case 1:
            getElement();
            break;
        case 2:
            setElement();
            break;
        case 3:
            readMatrix();
            break;
        case 4:
            showMatrix();
            break;
        case 5:
            sum();
            break;
        case 6:
            mul();
            break;
        }

    }
    while(n != 0 || cin.fail());
}

void Menu::showMenu()
{
    cout << "\n";
    cout << "|-------------------------------------------|\n";
    cout << "|  0. - Kilepes." << setw(30) << "|\n";
    cout << "|  1. - Egy elem lekerese." << setw(20) << "|\n";
    cout << "|  2. - Egy elem felulirasa." << setw(18) << "|\n";
    cout << "|  3. - Matrix beolvasas." << setw(21) << "|\n";
    cout << "|  4. - Mutasd a matrixot." << setw(20) << "|\n";
    cout << "|  5. - Egy masik matrixal valo osszeadas." << setw(4) << "|\n";
    cout << "|  6. - Egy masik matrixal valo szorzas." << setw(6) << "|\n";
    cout << "|-------------------------------------------|\n";
    cout << "\n";
}

void Menu::getElement() const
{
    int i, j;
    cout << "  Sor index (i): ";
    cin >> i;
    cout << "  Oszlop index (j): ";
    cin >> j;

    try
    {
        cout << "  M[" << i << ", " << j << "]= " << _x(i - 1, j - 1) << endl;
    }
    catch(NMX::Exceptions ex)
    {
        if(ex == NMX::OVERINDEX)
            cout << "  Tulindexelt!\n";
        else
            cout << "  Kezeletlen kivetel\n";
    }
}

void Menu::setElement()
{
    int i, j, e;
    cout << "  Sor index (i): ";
    cin >> i;
    cout << "  Oszlop index (j): ";
    cin >> j;
    cout << "  Elem: ";
    cin >> e;

    try
    {
        _x(i-1,j-1) = e;
    }
    catch(NMX::Exceptions ex)
    {
        if(ex == NMX::OVERINDEX)
            cout << "  Tulindexelt!\n";
        else if(ex == NMX::NULLPART)
            cout << "  Az index nem mutat az N alakba!\n";
        else
            cout << "  Kezeletlen kivetel!\n";
    }
}

void Menu::readMatrix()
{
    try
    {
        cout << "  Add meg a matrix meretet, majd az elemeit: ";
        cin >> _x;
    }
    catch(NMX::Exceptions ex)
    {
        if(ex == NMX::NEGATIVSIZE)
            cout << "  Negativ meret!\n";
        else if(ex == NMX::NO_MATRIX)
            cout << "  Nulla meret!\n";
        else
            cout << "  Kezeletlen kivetel!\n";
    }
}

void Menu::showMatrix()
{
    cout << _x << endl;
}

void Menu::sum()
{
    try
    {
        NMX y;
        cout << "  Add meg a 2. matrix meretet es elemeit: ";
        cin >> y;
        cout << "\n  A ket matrix osszege:\n\n";
        cout << _x + y << endl;
    }
    catch(NMX::Exceptions ex)
    {
        if(ex == NMX::DIFFERENT)
            cout << "  A ket matrix merete elter!\n";
        else if(ex == NMX::NEGATIVSIZE)
            cout << "  Negativ meret!\n";
        else if(ex == NMX::NO_MATRIX)
            cout << "  Nulla meret!\n";
        else
            cout << "  Kezeletlen kivetel!\n";
    }
}

void Menu::mul()
{
    try
    {
        NMX y;
        cout << "  Add meg a 2. matrix meretet es elemeit: ";
        cin >>  y;
        cout << "\n  A ket matrix szorzata:\n\n";
        cout << _x * y << endl;
    }
    catch(NMX::Exceptions ex)
    {
        if(ex == NMX::DIFFERENT)
            cout << "  A ket matrix merete elter!\n";
        else if(ex == NMX::NEGATIVSIZE)
            cout << "  Negativ meret!\n";
        else if(ex == NMX::NO_MATRIX)
            cout << "  Nulla meret!\n";
        else
            cout << "  Kezeletlen kivetel!\n";
    }
}
