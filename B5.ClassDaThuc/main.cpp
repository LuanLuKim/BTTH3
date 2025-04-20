#include <iostream>
#include "cDaThuc.h"

using namespace std;

int main()
{
    cDaThuc f1, f2;

    cout << "Nhap da thuc thu nhat (so mu giam dan):\n";
    f1.nhap();

    cout << "\nNhap da thuc thu hai (so mu giam dan):\n";
    f2.nhap();

    cout << "\nDa thuc thu nhat: ";
    f1.xuat();

    cout << "Da thuc thu hai: ";
    f2.xuat();

    cDaThuc tong = f1 + f2;
    cDaThuc hieu = f1 - f2;

    cout << "\nTong hai da thuc: ";
    tong.xuat();
    cout << "Hieu hai da thuc: ";
    hieu.xuat();

    float x;
    cout << "\nNhap gia tri x de tinh gia tri da thuc thu nhat: ";
    cin >> x;
    cout << "Gia tri da thuc tai x = " << x << " la: " << f1.tinhGiaTri(x) << endl;
}