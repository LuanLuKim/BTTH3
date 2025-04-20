#pragma once
#include "Diem.h"
class cDaGiac : public Diem
{
private:
    Diem* ds;
    int n;

public:
    cDaGiac()
    {
        ds = NULL;
        n = 0;
    }
    ~cDaGiac()
    {
        delete[] ds;
    }

    void Nhap();
    void Xuat();

    void TinhTien(double x, double y);
    void PhongTo(double scale);
    void ThuNho(double scale);
    void Quay(double goc);

    double ChuVi();
    double DienTich();
};

