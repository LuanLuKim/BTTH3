#include "Diem.h"
#define PI 2 * acos(0)


// Ham Distant tinh khoang cach giua 2 diem
// Input: Toa do 2 diem A, B
// Output: Khoang cach Euclid giua 2 diem
// Huong giai quyet: Dung cong thuc tinh khoang cach giua 2 diem
double Diem:: Distant(const Diem& A, const Diem& B)
{
	double dis = sqrt((A.dx - B.dx) * (A.dx - B.dx) + (A.dy - B.dy) * (A.dy - B.dy));
	return dis;
}

// Ham nhap toa do cho diem
// Input: Nhap tu ban phim toa do x y
// Output: Khong co
// Huong giai quyet: Dung cin de nhap gia tri cho dx, dy
void Diem:: Nhap()
{
	cin >> dx >> dy;
}

// Ham xuat toa do cho diem
// Input: Khong co
// Output: Xuat toa do ra man hinh
// Huong giai quyet: Dung cout de xuat gia tri dx, dy ra man hinh
void Diem::Xuat()
{
	cout << "( " << dx << ", " << dy << " )";
}

// Ham tinh tien 1 diem
// Input: 2 so thuc de tinh tien
// Outptu: Khong co
// Huong giai quyet: Cong truc tiep 2 so thuc tuong ung voi dx, dy
void Diem::TinhTien(double x, double y)
{
	dx += x;
	dy += y;
}

// Ham phong to
// Input: 1 so thuc scale
// Outptu: Khong co
// Huong giai quyet: Nhan dx, dy cho scale
void Diem::PhongTo(double scale)
{
	dx *= scale;
	dy *= scale;
}

// Ham thu nho
// Input: 1 so thuc scale
// Outptu: Khong co
// Huong giai quyet: Chia dx, dy cho scale
void Diem::ThuNho(double scale)
{
	dx /= scale;
	dy /= scale;
}

// Ham quay 1 diem quanh goc toa do
// Input: 1 so thuc alpha dai dien cho goc quay (tinh theo do)
// Outptu: Khong co
// Huong giai quyet: Ap dung cong thuc quay 1 diem quanh goc toa do
void Diem::Quay(double alpha)
{
	double x, y;
	x = dx * cos(alpha * PI / 180) - dy * sin(alpha * PI / 180);
	y = dx * sin(alpha * PI / 180) + dy * cos(alpha * PI / 180);
	dx = x;
	dy = y;
}