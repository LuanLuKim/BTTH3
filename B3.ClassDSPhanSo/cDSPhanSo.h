#pragma once
#include "PhanSo.h"
class cDSPhanSo : public PhanSo
{
private:
    PhanSo* ds;
    int n;

public:
    cDSPhanSo() { ds = NULL, n = 0; }
    ~cDSPhanSo() 
    {
        delete[] ds;
        n = 0;
    }

    void Nhap();
    void Xuat() const;

    PhanSo TinhTong() const;
    PhanSo PhanSoMax() const;
    PhanSo PhanSoMin() const;
    PhanSo PhanSoTuNTMax() const;

    void SapXepTang(int left, int right);
    void SapXepGiam(int left, int right);

    // Ham lay so luong phan tu
    // Input: Khong co
    // Output: Tra ve so nguyen n (so luong phan so)
    int getSoLuong() { return n; }
};

