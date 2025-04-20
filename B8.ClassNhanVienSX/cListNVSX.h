#pragma once
#include "cNhanVienSX.h"
#include <vector>
class cListNVSX : public cNhanVienSX
{
private:
	vector<cNhanVienSX> ds;
	int soLuong;
public:
	cListNVSX() { soLuong = 0; }
	~cListNVSX() {}
	void Nhap();
	void Xuat();
	cNhanVienSX timNhanVienLuongThapNhat() const;
	long long tinhTongLuong() const;
	cNhanVienSX timNhanVienTuoiCaoNhat() const;
	void sortLuongTangDan(int left, int right);
	// Ham lay so luong nhan vien
	// Input: Khong co
	// Output: Tra ve so luong nhan vien
	int getSoLuong() { return soLuong; }
};

