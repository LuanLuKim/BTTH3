#include <iostream>
#include "cDSPhanSo.h"

using namespace std;

int main()
{
    cDSPhanSo danhSach;
    danhSach.Nhap();
    if (danhSach.getSoLuong() == 0)
        return 0;

    cout << "\nDanh sach phan so:\n";
    danhSach.Xuat();

    cout << "\nTong cac phan so: ";
    danhSach.TinhTong().Xuat();

    cout << "\nPhan so lon nhat: ";
    danhSach.PhanSoMax().Xuat();

    cout << "\nPhan so nho nhat: ";
    danhSach.PhanSoMin().Xuat();

    PhanSo ps; ps = danhSach.PhanSoTuNTMax();
    if (ps.getTu() == 0) cout << "\nKhong ton tai phan so co tu la so nguyen to";
    else
    {
        cout << "\nPhan so co tu la so nguyen to lon nhat: ";
        ps.Xuat();
    }

    cout << "\nDanh sach tang dan:\n";
    danhSach.SapXepTang(0, danhSach.getSoLuong()-1);
    danhSach.Xuat();

    cout << "\nDanh sach giam dan:\n";
    danhSach.SapXepGiam(0, danhSach.getSoLuong()-1);
    danhSach.Xuat();

    return 0;
}