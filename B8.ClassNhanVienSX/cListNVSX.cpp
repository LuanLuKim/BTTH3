#include "cListNVSX.h"
// Ham toan tu nho hon giua 2 doi tuong DateTime
// Input: thisTime, other - 2 ngay can so sanh
// Output: True neu thisTime nho hon other, nguoc lai false
// Huong giai quyet: So sanh theo thu tu nam -> thang -> ngay
bool operator<(const DateTime& thisTime, const DateTime& other)
{
    if (thisTime.year != other.year) return thisTime.year < other.year;
    if (thisTime.month != other.month) return thisTime.month < other.month;
    return thisTime.day < other.day;
}
// Ham tim nhan vien co luong thap nhat trong danh sach
// Input: Khong co
// Output: Tra ve doi tuong nhan vien co luong thap nhat
// Huong giai quyet: Duyet toan bo danh sach va tim nhan vien co luong nho nhat
cNhanVienSX cListNVSX:: timNhanVienLuongThapNhat() const
{
    cNhanVienSX minLuongNV = ds[0];
    for (const auto& nv : ds)
    {
        if (nv.tinhLuong() < minLuongNV.tinhLuong())
        {
            minLuongNV = nv;
        }
    }
    return minLuongNV;
}
// Ham tinh tong luong cua tat ca nhan vien san xuat
// Input: Khong co
// Output: Tra ve tong luong
// Huong giai quyet: Duyet qua danh sach ds va cong don luong cua tung nhan vien
long long cListNVSX::tinhTongLuong() const
{
    long long tongLuong = 0;
    for (const cNhanVienSX& nv : ds)
    {
        tongLuong += nv.tinhLuong();
    }
    return tongLuong;
}
// Ham tim nhan vien co tuoi cao nhat
// Input: Khong co
// Output: Tra ve nhan vien co tuoi lon nhat
// Huong giai quyet: Su dung toan tu < de so sanh ngay sinh va tim nguoi sinh som nhat
cNhanVienSX cListNVSX::timNhanVienTuoiCaoNhat() const
{
    cNhanVienSX maxTuoiNV = ds[0];
    for (const cNhanVienSX& nv : ds)
    {
        if (nv.getNgaySinh() < maxTuoiNV.getNgaySinh())
        {
            maxTuoiNV = nv;
        }
    }
    return maxTuoiNV;
}

// Ham phan hoach trong thuat toan quicksort
// Input:
// - ds: vector nhan vien (tham chieu)
// - left, right: chi so trai va phai cua mang con
// - i, j: bien tra ve vi tri phan hoach (tham chieu)
// Output: cap nhat lai vi tri i, j (thong qua tham chieu)
// Huong giai quyet:
// - Chon pivot o giua
// - Duyet tu 2 dau, swap neu can
void partition(vector<cNhanVienSX>& ds, int left, int right, int& i, int& j)
{
    if (left >= right) return;

    i = left, j = right;
    int pivot = ds[left + (right - left) / 2].tinhLuong();
    while (i <= j)
    {
        while (ds[i].tinhLuong() < pivot) i++;
        while (ds[j].tinhLuong() > pivot) j--;

        if (i <= j)
        {
            cNhanVienSX temp = ds[i];
            ds[i] = ds[j];
            ds[j] = temp;
            i++, j--;
        }
    }
}
// Sap xep danh sach nhan vien theo luong tang dan (quicksort)
// Input: left va right chi dinh doan can sap xep trong vector ds
// Output: Danh sach ds duoc sap xep theo thu tu tang dan ve luong
// Huong giai quyet:
// - Goi ham partition de chia mang thanh 2 phan
// - De quy sap xep tung phan
void cListNVSX::sortLuongTangDan(int left, int right)
{
    if (left < right)
    {
        int i, j;
        partition(ds, left, right, i, j);

        sortLuongTangDan(left, j);
        sortLuongTangDan(i, right);
    }
}
// Ham nhap danh sach nhan vien san xuat
// Input: Nhap so luong, sau do nhap thong tin tung nhan vien
// Output: Luu danh sach nhan vien vao vector ds
void cListNVSX::Nhap()
{
    cout << "Nhap so luong nhan vien san xuat: ";
    cin >> soLuong;

    for (int i = 0; i < soLuong; i++)
    {
        cout << "\nNhap thong tin nhan vien thu " << i + 1 << ":\n";
        cNhanVienSX nv;
        nv.Nhap();
        ds.push_back(nv);
    }
}
// Ham xuat danh sach nhan vien ra man hinh
// Input: Khong co
// Output: Hien thi thong tin tung nhan vien trong ds neu co
void cListNVSX::Xuat()
{
    if (soLuong == 0) return;

    cout << "\nDanh sach nhan vien:\n";
    for (const cNhanVienSX& nv : ds)
    {
        nv.Xuat();
    }
}