#include "DonThuc.h"
#include <cmath>
#include <iostream>

using namespace std;

float DonThuc::tinhGiaTri(float x) const 
{
    return heSo * pow(x, soMu);
}

void DonThuc::xuat() const 
{
    if (soMu == 0)
        cout << heSo;
    else
    {
        if (heSo != 1 && heSo != -1)
        {
            if (soMu == 1)
                cout << heSo << "x";
            else
                cout << heSo << "x^" << soMu;
        }
        else if (heSo == -1)
        {
            if (soMu == 1)
                cout << "-x";
            else
                cout << "-x^" << soMu;
        }
        else
        {
            if (soMu == 1)
                cout << "x";
            else
                cout << "x^" << soMu;
        }
    }
}

