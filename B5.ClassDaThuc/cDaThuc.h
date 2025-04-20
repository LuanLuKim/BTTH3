#pragma once
#include "DonThuc.h"
#include <iostream>

using namespace std;

class cDaThuc : public DonThuc
{
private:
	DonThuc* dt;
	int soLuong;
public:
	cDaThuc() { dt = NULL; soLuong = 0; }
	cDaThuc(const cDaThuc& other);
	cDaThuc& operator=(const cDaThuc& other);
	~cDaThuc() { delete[] dt; }

	void nhap();
	void xuat() const;
	float tinhGiaTri(float x) const;

	cDaThuc operator +(const cDaThuc& b) const;
	cDaThuc operator -(const cDaThuc& b) const;
};

