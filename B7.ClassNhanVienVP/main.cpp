#include <iostream>
#include "cListNVVP.h"

using namespace std;

int main() 
{
	cListNVVP ds;
	ds.Nhap();
	ds.Xuat();

	if (ds.getSoLuong() == 0)
		return 0;
	cNhanVienVP maxLuongNV = ds.timNhanVienLuongCaoNhat();
	cout << "\nNhan vien co luong cao nhat:\n";
	maxLuongNV.Xuat();

	cout << "\nTong luong cong ty phai tra: " << ds.tongLuong() << endl;

	cNhanVienVP maxTuoiNV = ds.timNhanVienTuoiCaoNhat();
	cout << "\nNhan vien co tuoi cao nhat:\n";
	maxTuoiNV.Xuat();

	cout << "Danh sach sau khi da sap xep tang dan theo luong";
	ds.sortLuongTangDan(0,ds.getSoLuong()-1);
	ds.Xuat();

	return 0;
}
