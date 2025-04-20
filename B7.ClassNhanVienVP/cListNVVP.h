#pragma once
#include "cNhanVienVP.h"
class cListNVVP : public cNhanVienVP
{
private:
	vector<cNhanVienVP> ds;
	int soLuong;
public:
	cListNVVP() {}
	~cListNVVP(){}
	void Nhap();
	void Xuat();
	cNhanVienVP timNhanVienLuongCaoNhat();
	cNhanVienVP timNhanVienTuoiCaoNhat();
	long long tongLuong();
	void sortLuongTangDan( int left, int right);
	// Ham lay so luong nhan vien
	// Input: Khong co
	// Output: Tra ve so luong nhan vien
	int getSoLuong() { return soLuong; }
};

