#include "cNhanVienSX.h"

// Ham nhap du lieu cho bien ngay sinh kieu DateTime
// Input: Tu ban phim, nhap vao ngay, thang, nam
// Output: Gan gia tri ngay, thang, nam vao bien NgaySinh
void nhap(DateTime& NgaySinh)
{
    cout << "Nhap ngay sinh (dd mm yyyy): ";
    cin >> NgaySinh.day >> NgaySinh.month >> NgaySinh.year;
}
// Ham xuat ngay sinh ra man hinh
// Input: NgaySinh kieu DateTime
// Output: Hien thi ngay sinh theo dinh dang dd/mm/yyyy
void xuat(const DateTime& NgaySinh)
{
    cout << NgaySinh.day << "/" << NgaySinh.month << "/" << NgaySinh.year;
}
// Phuong thuc nhap thong tin cho doi tuong nhan vien san xuat
// Input: Tu ban phim, nhap ma nhan vien, ho ten, ngay sinh, so san pham, don gia
// Output: Gan cac gia tri vua nhap cho cac thuoc tinh tuong ung
void cNhanVienSX::Nhap()
{
    cout << "Nhap ma nhan vien: ";
    cin >> maNV;
    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    nhap(ngaySinh);
    cout << "Nhap so san pham da gia cong: ";
    cin >> soSanPham;
    cout << "Nhap don gia mot san pham: ";
    cin >> donGia;
}
// Phuong thuc xuat thong tin cua doi tuong nhan vien san xuat ra man hinh
// Input: Khong co
// Output: Hien thi ma nhan vien, ho ten, ngay sinh, va luong tinh duoc
void cNhanVienSX::Xuat() const
{
    cout << "Ma: " << maNV << "\tTen: " << hoTen << "\nNgay sinh: "; xuat(ngaySinh);
    cout << "\tLuong: " << tinhLuong() << endl;
}

