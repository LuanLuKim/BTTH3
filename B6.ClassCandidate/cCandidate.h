#pragma once
#include <iostream>
#include <string>

using namespace std;
struct DateTime
{
    int ngay, thang, nam;
};

class cCandidate
{
private:
    string ma, ten;
    DateTime ngaySinh;
    double diemToan, diemVan, diemAnh;

public:
    // Ham khoi tao khong co doi do
    // Input: Khong co
    // Output: Tao object cCandidate voi ma = ten = rong 
    //             diemToan = diemAnh = diemAnh = 0
    //             ngaySinh.thang = ngaySinh.ngay = ngaySinh.nam = 0
    cCandidate() 
    {
        ngaySinh.thang = ngaySinh.ngay = ngaySinh.nam = 0;
        ma = ten = "";
        diemToan = diemAnh = diemVan = 0;
    }
    ~cCandidate(){}
    void nhap();
    void xuat() const;
    // Ham tinh tong diem
    // Input: Khong co
    // Output: So thuc la tong diem cua thi sinh
    // Huong giai quyet: Cong 3 so diemToan, diemVan va diemAnh
    double tongDiem() const
    {
        return diemToan + diemVan + diemAnh;
    }
};

