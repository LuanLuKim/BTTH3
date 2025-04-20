#include "cDaGiac.h"
#include <iostream>
#include <cmath>
using namespace std;

#define PI 2 * acos(0)
// Nhap du lieu da giac
// Input: Khong co
// Output: Khong co
// Huong giai quyet: Dung cin de nhap du lieu cho cac diem
void cDaGiac::Nhap() 
{
    do 
    {
        cout << "Nhap so dinh cua da giac (>= 3): ";
        cin >> n;
        if (n < 3)
        {
            cout << "Khong phai da giac" << endl;
            continue;
        }
    } while (n < 3);
    ds = new Diem[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap diem thu " << i + 1 << ": ";
        ds[i].Nhap();
    }
}

// Xuat thong tin cac dinh cua da giac
// Input: Khong co
// Output: Khong co
// Huong giai quyet: Dung cout de xuat thong tin da giac
void cDaGiac::Xuat() 
{
    cout << "Da giac co " << n << " dinh: ";
    for (int i = 0; i < n-1; i++)
    {
        ds[i].Xuat();
        cout << ", ";
    }
    ds[n - 1].Xuat();
    cout << endl;
}

// Tinh tien da giac theo vector (x, y)
// Input: x, y la vector tinh tien
// Output: Khong co
// Huong giai quyet: Cong truc tiep gia tri cua vector cho lan luot tung diem de tinh tien
void cDaGiac::TinhTien(double x, double y) 
{
    for (int i = 0; i < n; i++)
        ds[i].TinhTien(x, y);
}

// Phong to da giac theo ty le scale
// Input: 1 gia tri scale > 0
// Output: Khong co
// Huong giai quyet: Nhan cac diem cho scale
void cDaGiac::PhongTo(double scale) 
{
    for (int i = 0; i < n; i++)
        ds[i].PhongTo(scale);
}

// Thu nho da giac theo ty le scale
// Input: scale > 0
// Output: Khong co
// Huong giai quyet: Chia cac diem cho scale
void cDaGiac::ThuNho(double scale) 
{
    for (int i = 0; i < n; i++)
        ds[i].ThuNho(scale);
}

// Quay da giac quanh goc toa do
// Input: Goc quay (don vi do)
// Output: Khong co
// Huong giai quyet: Dung cong thuc quay 1 diem quanh goc toa do
void cDaGiac::Quay(double goc) 
{
    for (int i = 0; i < n; i++)
        ds[i].Quay(goc);
}

// Tinh chu vi da giac
// Input: Khong
// Output: Chu vi da giac
// Huong giai: Tong kich thuoc cac canh tao tu cac dinh lien tiep
double cDaGiac::ChuVi() 
{
    double cv = 0;
    for (int i = 0; i < n - 1; i++)
        cv += Diem::Distant(ds[i], ds[i + 1]);
    cv += Diem::Distant(ds[n - 1], ds[0]);
    return cv;
}


// Tinh dien tich da giac
// Input: Khong
// Output: Dien tich cua da giac 
// Huong giai: Theo cong thuc Shoelace
double cDaGiac::DienTich() 
{
    double s = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        s += ds[i].getdx() * ds[j].getdy() - ds[j].getdx() * ds[i].getdy();
    }
    s = fabs(s) / 2;
    return s;
}
