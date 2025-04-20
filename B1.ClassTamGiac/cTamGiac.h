#pragma once
#include "Diem.h"
#include <string>

double Distant(const Diem &A, const Diem &B);
class cTamGiac : public Diem
{
private:
	Diem A, B, C;
public:
	cTamGiac(){}
	cTamGiac(Diem a, Diem b, Diem c) : A(a), B(b), C(c) {}
	~cTamGiac(){}
	void Nhap();
	void Xuat();
	string PhanLoai();
	double TinhchuVi();
	double TinhDienTich();
	void TinhTien(double x, double y)
	{
		A.TinhTien(x, y);
		B.TinhTien(x, y);
		C.TinhTien(x, y);
	}
	void PhongTo(double scale)
	{
		A.PhongTo(scale);
		B.PhongTo(scale);
		C.PhongTo(scale);
	}
	void ThuNho(double scale)
	{
		A.ThuNho(scale);
		B.ThuNho(scale);
		C.ThuNho(scale);
	}
	void Quay(double alpha)
	{
		A.Quay(alpha);
		B.Quay(alpha);
		C.Quay(alpha);
	}
};

