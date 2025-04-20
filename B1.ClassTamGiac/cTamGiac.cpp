#include "cTamGiac.h"

// Ham nhap toa do cho 3 dinh
// Input: Nhap tu ban phim toa do 3 dinh
// Output: Khong co
// Huong giai quyet: Dung ham Nhap cua diem de nhap toa do cho 3 dinh A, B, C
void cTamGiac::Nhap()
{
	cout << "Nhap toa do cho diem A: "; A.Nhap();
	cout << "Nhap toa do cho diem B: "; B.Nhap();
	cout << "Nhap toa do cho diem C: "; C.Nhap();
}
// Ham nhap toa do cho 3 dinh
// Input: Khong co
// Output: Toa do 3 dinh ra man hinh
// Huong giai quyet: Dung ham Xuat cua diem de xuat toa do cho 3 dinh A, B, C
void cTamGiac::Xuat()
{
	cout << "Tam giac ABC gom: " << endl;
	cout << "A: "; A.Xuat();
	cout << "B: "; B.Xuat();
	cout << "C: "; C.Xuat();
}

// Ham phan loai tam giac
// Input: Khong co
// Output: Loai tam giac
// Huong giai quyet: Tinh khoang cach 3 canh roi so sanh xem la loai tam giac gi
string cTamGiac::PhanLoai()
{
	double a = Distant(B, C);
	double b = Distant(A, C);
	double c = Distant(B, A);
	if (a + b > c && a + c > b && b + c > a)
	{
		if (abs(a-b)<=1e-8 && abs(b-c)<=1e-8) return "DEU";
		else if (abs(a * a + b * b - c * c)<= 1e-9 ||abs( a * a + c * c - b * b) <= 1e-9 ||abs( b * b + c * c - a * a) <= 1e-9)
		{
			if (a == b || b == c || a == c)
				return "VUONG CAN";
			return "VUONG";
		}
		else if (a == b || b == c || a == c)
		{
			return "CAN";
		}
		else return "THUONG";
	}
	else
		return"-1";
}
// Ham tinh chu vi
// Input: Khong co
// Output: Chu vi tam giac
// Huong giai quyet: Tinh khoang cach 3 canh roi cong lai
double cTamGiac::TinhchuVi()
{
	double a = Distant(B, C);
	double b = Distant(A, C);
	double c = Distant(B, A);
	return a + b + c;
}

// Ham tinh dien tich
// Input: Khong co
// Output: Dien tich tam giac
// Huong giai quyet: Tinh khoang cach 3 canh roi dung cong thuc heron de tinh dien tich
double cTamGiac::TinhDienTich()
{
	double a = Distant(B, C);
	double b = Distant(A, C);
	double c = Distant(B, A);
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}
