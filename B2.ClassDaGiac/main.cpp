#include <iostream>
#include "cDaGiac.h"

using namespace std;

int main()
{
    cDaGiac daGiac;
    daGiac.Nhap();
    daGiac.Xuat();

    double cv = daGiac.ChuVi();
    double dt = daGiac.DienTich();
    if (dt == 0)
    {
        cout << "Khong phai da giac";
        return 0;
    }
    cout << "Chu vi da giac: " << cv << endl;
    cout << "Dien tich da giac: " << dt << endl;

    cout << "Nhap vector tinh tien: ";
    double x, y; cin >> x >> y;
    daGiac.TinhTien(x, y);
    daGiac.Xuat();

    cout << "Nhap he so phong to: ";
    double scale; cin >> scale;
    daGiac.PhongTo(scale);
    daGiac.Xuat();

    cout << "Nhap he so thu nho: ";
    cin >> scale;
    daGiac.ThuNho(scale);
    daGiac.Xuat();

    cout << "Nhap goc quay: ";
    double goc; cin >> goc;
    daGiac.Quay(goc);
    daGiac.Xuat();

    return 0;
}