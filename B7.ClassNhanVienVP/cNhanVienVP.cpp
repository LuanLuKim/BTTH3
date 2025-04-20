#include "cNhanVienVP.h"

// Ham nhap ngay sinh cho nhan vien
// Input: tham chieu den bien NgaySinh kieu DateTime
// Output: cap nhat gia tri day, month, year cua bien NgaySinh
// Huong giai quyet:
// - Yeu cau nguoi dung nhap vao ngay, thang, nam
// - Luu vao bien cau truc DateTime thong qua tham chieu
void nhap(DateTime& NgaySinh)
{
    cout << "Nhap ngay sinh (dd mm yyyy): ";
    cin >> NgaySinh.day >> NgaySinh.month >> NgaySinh.year;
}
// Ham xuat ngay sinh ra man hinh
// Input: tham chieu hang den bien NgaySinh (kieu DateTime)
// Output: hien thi ngay sinh theo dinh dang dd/mm/yyyy
// Huong giai quyet:
// - Doc cac truong day, month, year cua bien NgaySinh
// - In ra theo dinh dang ngay/thang/nam
void xuat(const DateTime& NgaySinh)
{
    cout << NgaySinh.day << "/" << NgaySinh.month << "/" << NgaySinh.year;
}
// Phuong thuc nhap du lieu cho doi tuong nhan vien
// Input: duoc nhap tu ban phim
// Output: cap nhat cac thuoc tinh maNV, hoTen, ngaySinh, luong
// Huong giai quyet:
// - Nhap ma nhan vien (maNV) bang cin
// - Dung getline de nhap ho ten (hoTen) co dau cach
// - Goi ham nhap() de nhap ngay sinh
// - Nhap luong (kieu so)
void cNhanVienVP::Nhap()
{
    cout << "Nhap ma nhan vien: ";
    cin >> maNV;
    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    nhap(ngaySinh);
    cout << "Nhap luong (Don vi dong): ";
    cin >> luong;
}
// Phuong thuc xuat thong tin nhan vien ra man hinh
// Input: khong co (doc du lieu tu cac thuoc tinh cua doi tuong)
// Output: hien thi ma nhan vien, ho ten, ngay sinh, luong
// Huong giai quyet:
// - In thong tin maNV, hoTen
// - Goi ham xuat() de in ngay sinh
// - In gia tri luong
void cNhanVienVP::Xuat() const
{
    cout << "Ma: " << maNV << "\tTen: " << hoTen << "\nNgay sinh: "; xuat(ngaySinh);
    cout << "\tLuong: " << luong << endl;
}
