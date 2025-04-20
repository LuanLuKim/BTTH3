#include <iostream>
#include "cListNVSX.h"

using namespace std;

int main() 
{
	cListNVSX ds;
	ds.Nhap();
	ds.Xuat();
	if (ds.getSoLuong() == 0)
	{
		cout << "Danh sach rong.";
		return 0;
	}

	cNhanVienSX minLuongNV = ds.timNhanVienLuongThapNhat();
	cout << "\nNhan vien co luong thap nhat:\n";
	minLuongNV.Xuat();


	cout << "\nTong luong cong ty phai tra: " << ds.tinhTongLuong() << endl;

	cNhanVienSX maxTuoiNV = ds.timNhanVienTuoiCaoNhat();
	cout << "\nNhan vien co tuoi cao nhat:\n";
	maxTuoiNV.Xuat();

	cout << "\nDanh sach nhan vien sau khi sap xep theo luong tang dan:\n";
	ds.sortLuongTangDan(0, ds.getSoLuong() - 1);
	ds.Xuat();
	return 0;
}
