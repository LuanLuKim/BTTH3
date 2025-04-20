#pragma once
#include <iostream>
#include <cmath>
#include <numbers>

using namespace std;
class Diem
{
protected:
	double dx, dy;
public:
	Diem() { dx = dy = 0; }
	Diem(double x, double y) : dx(x), dy(y){}
	~Diem(){}
	void Nhap();
	void Xuat();
	void TinhTien(double x, double y);
	void PhongTo(double scale);
	void ThuNho(double scale);
	void Quay(double scale);
	double Distant(const Diem &A, const Diem &B);
};

