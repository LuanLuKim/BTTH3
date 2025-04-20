#include "cCandidate.h"
#include <iomanip>

void cCandidate::nhap()
{
    cout << "Nhap ma thi sinh: "; cin >> ma;
    cin.ignore();
    cout << "Nhap ten thi sinh: "; getline(cin, ten);
    cout << "Nhap ngay sinh (dd mm yyyy): "; cin >> ngaySinh.ngay>>ngaySinh.thang>>ngaySinh.nam;
    cout << "Nhap diem Toan (0-10): "; cin >> diemToan;
    cout << "Nhap diem Van (0-10): "; cin >> diemVan;
    cout << "Nhap diem Anh (0-10): "; cin >> diemAnh;
}

void cCandidate::xuat() const
{
    cout << "Ma: " << ma << "\nTen: " << ten << "\nNgay sinh: " << setw(2) << setfill('0')<< ngaySinh.ngay;
    cout << '/' << setw(2) << setfill('0') << ngaySinh.thang;
    cout << '/' << ngaySinh.nam;
    cout << "\nTong diem: " << tongDiem() << endl;
}
