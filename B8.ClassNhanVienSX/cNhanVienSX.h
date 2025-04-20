#pragma once
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

struct DateTime 
{
    int day, month, year;
};

class cNhanVienSX
{
private:
    string maNV;
    string hoTen;
    DateTime ngaySinh;
    int soSanPham;
    long long donGia;
public:
    // Ham khoi tao khong doi
    // Input: Khong co
    // Output: Doi tuong rong lop cNhanVienSX
    // Huong giai quyet:
    // - Gan ma nhan vien va ho ten la chuoi rong
    // - Gan ngay sinh ve 0
    // - Gan soSanPham = donGia = 0
    cNhanVienSX() 
    {
        maNV = hoTen = "";
        ngaySinh.day = ngaySinh.month = ngaySinh.year = 0;
        soSanPham = donGia = 0;
    }
    ~cNhanVienSX(){}
    void Nhap();
    void Xuat() const;
    // Ham tinh luong cua nhan vien
    // Input: Khong co
    // Output: Tien luong duoc tinh 
    // Huong giai quyet: Nhan luong dua tren so san pham va don gia cua tung san pham
    long long tinhLuong() const { return soSanPham * donGia; }
    // Ham tra ve ngay sinh cua nhan vien
    // Input: Khong co
    // Output: Tra ve ngay sinh kieu DateTime
    DateTime getNgaySinh() const { return ngaySinh; }
    // Ham tra ve ho ten cua nhan vien
    // Input: Khong co
    // Output: Tra ve ho ten kieu string
    string getHoTen() const { return hoTen; }
};

