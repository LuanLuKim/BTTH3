#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class PhanSo
{
protected:
    int tu, mau;
public:
    PhanSo() 
    {
        tu = 0; mau = 1;
    }
    ~PhanSo(){}

    void Nhap();
    void Xuat() const;
    void RutGon();
    int getTu() const;

    bool operator<(const PhanSo& ps) const;
    bool operator>(const PhanSo& ps) const;
    PhanSo operator+(const PhanSo& ps) const;
};

