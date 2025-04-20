#include <iostream>
#include "cArray.h"

using namespace std;

int main()
{
    cArray arr;
    arr.generateRandom();

    cout << "\nMang ban dau:\n";
    arr.Xuat();

    bool ascending = arr.isAscending();
    if (ascending)
        cout << "Mang vua nhap da tang dan\n";
    else
        cout << "Mang vua nhap khong tang dan\n";

    int x;
    cout << "Nhap vao gia tri muon dem so lan xuat hien: "; cin >> x;
    cout <<"Gia tri "<<x<<" da xuat hien "<< arr.count(x)<<" lan trong mang\n";

    int* p = arr.minOdd();
    if (p == NULL)
        cout << "Mang khong ton tai so le\n";
    else
        cout << "So le nho nhat: " << *p<<endl;

    int maxPrime = arr.maxPrime();
    if (maxPrime == -1)
        cout << "Mang khong ton tai so nguyen to\n";
    else
        cout << "So nguyen to lon nhat trong mang: " << maxPrime<<endl;

    if (!ascending)
    {
        cout << "\nMang sau khi sap xep tang dan:\n";
        arr.sortAsc(0, arr.size() - 1);
        arr.Xuat();
    }

    cout << "\nMang sau khi sap xep giam dan:\n";
    arr.sortDesc(0, arr.size() - 1);
    arr.Xuat();

    return 0;
}