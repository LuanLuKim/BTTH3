#include <iostream>
#include "cTamGiac.h"
using namespace std;

int main()
{
    cTamGiac tg1;
    tg1.Nhap();
    tg1.Xuat();
	string loai = tg1.PhanLoai();
	if (loai == "-1")
	{
		cout << "KHONG PHAI TAM GIAC";
		return 0;
	}
	else
	{
		cout << "Day la tam giac: " << loai << endl;

		cout << "Chu vi tam giac = " << tg1.TinhchuVi() << endl;
		cout << "Dien tich tam giac = " << tg1.TinhDienTich() << endl;

		cout << "Nhap vector de tinh tien tam giac: ";
		int x, y; cin >> x >> y;
		tg1.TinhTien(x, y);
		tg1.Xuat();

		cout << "Nhap gia tri muon phong to tam giac: ";
		double scale; cin >> scale;
		tg1.PhongTo(scale);
		tg1.Xuat();

		cout << "Nhap gia tri muon thu nho tam giac: ";
		cin >> scale;
		tg1.ThuNho(scale);
		tg1.Xuat();

		cout << "Nhap goc de xoay tam giac: ";
		double alpha; cin >> alpha;
		tg1.Quay(alpha);
		tg1.Xuat();

		return 0;
	}
}