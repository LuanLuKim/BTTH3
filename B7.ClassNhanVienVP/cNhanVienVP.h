#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct DateTime 
{
    int day, month, year;
};

class cNhanVienVP
{
private:
    string maNV;
    string hoTen;
    DateTime ngaySinh;
    long long luong;
public:
    // Ham khoi tao khong doi cua lop cNhanVienVP
    // Input: Khong co
    // Output: Tao mot doi tuong nhan vien rong
    // Huong giai quyet:
    // - Gan ma nhan vien (maNV) va ho ten (hoTen) la chuoi rong
    // - Gan ngay sinh (ngaySinh) ve 0 (day, month, year)
    // - Gan luong = 0
    cNhanVienVP() 
    {
        maNV = hoTen = "";
        luong = ngaySinh.day = ngaySinh.month = ngaySinh.year = 0;
    }
    ~cNhanVienVP(){}
    void Nhap();
    void Xuat() const;
    // Ham tra tra ve luong cua nhan vien
    // Input: Khong co
    // Output: Luong cua nhan vien
    long long getLuong() const { return luong; }
    // Ham tra ve ngay sinh cua nhan vien
    // Input: Khong co
    // Output: Tra ve ngay sinh cua nhan vien
    DateTime getNgaySinh() const { return ngaySinh; }
    // Ham lay ten cua nhan vien
    // Input: Khong co
    // Output: Tra ve ten cua nhan vien
    string getHoTen() const { return hoTen; }
    
};

