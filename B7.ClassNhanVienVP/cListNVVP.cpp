#include "cListNVVP.h"
// Ham toan tu < so sanh hai ngay sinh
// Input: thisTime va other (kieu DateTime)
// Output: Tra ve true neu thisTime nho hon other (tuc la tuoi lon hon)
// Huong giai quyet:
// - So sanh nam truoc, neu khac thi lay nam nho hon
// - Neu nam bang nhau, so sanh thang
// - Neu thang bang nhau, so sanh ngay
bool operator<(const DateTime& thisTime, const DateTime& other)
{
    if (thisTime.year != other.year) return thisTime.year < other.year;
    if (thisTime.month != other.month) return thisTime.month < other.month;
    return thisTime.day < other.day;
}
// Tim nhan vien co luong cao nhat trong danh sach
// Input: Khong co
// Output: tra ve nhan vien co luong cao nhat
// Huong giai quyet:
// - Duyet qua tat ca nhan vien trong ds
// - So sanh luong tung nhan vien voi max hien tai
// - Cap nhat max neu tim duoc nhan vien co luong cao hon
cNhanVienVP cListNVVP:: timNhanVienLuongCaoNhat()
{
    cNhanVienVP maxLuongNV = ds[0];
    for (const auto& nv : ds)
    {
        if (nv.getLuong() > maxLuongNV.getLuong())
        {
            maxLuongNV = nv;
        }
    }
    return maxLuongNV;
}
// Tim nhan vien co tuoi cao nhat trong danh sach
// Input: Khong co
// Output: Tra ve nhan vien co tuoi cao nhat
// Huong giai quyet:
// - Nguoi co tuoi cao nhat la nguoi co ngay sinh nho nhat
// - Su dung toan tu < da dinh nghia de so sanh ngay sinh
// - Duyet va cap nhat nhan vien co ngay sinh nho nhat
cNhanVienVP cListNVVP:: timNhanVienTuoiCaoNhat()
{
    cNhanVienVP maxTuoiNV = ds[0];
    for (const auto& nv : ds)
    {
        if (nv.getNgaySinh() < maxTuoiNV.getNgaySinh())
        {
            maxTuoiNV = nv;
        }
    }
    return maxTuoiNV;
}
// Tinh tong luong cua tat ca nhan vien trong danh sach
// Input: Khong co
// Output: Tra ve tong tien luong
// Huong giai quyet:
// - Duyet qua tung nhan vien trong danh sach
// - Cong don luong vao bien tongTien
long long cListNVVP::tongLuong()
{

    long long tongTien = 0;
    for (const auto& nv : ds)
    {
        tongTien += nv.getLuong();
    }

    return tongTien;
}
// Ham so sanh hai nhan vien theo luong (dung cho sap xep)
// Input: Doi tuong cNhanVienVP a va cNhanVienVP b
// Output: Tra ve true neu a co luong nho hon b
// Huong giai quyet:
// - Su dung de truyen vao cac thuat toan sap xep (neu dung sort cua thu vien)
bool cmp(const cNhanVienVP& a, const cNhanVienVP& b)
{
    return a.getLuong() < b.getLuong();
}
// Nhap danh sach nhan vien van phong
// Input: Nhap tu ban phim
// Output: Luu danh sach vao vector ds
// Huong giai quyet:
// - Nhap so luong nhan vien
// - Dung vong lap de nhap tung nhan vien bang ham Nhap cua lop cNhanVienVP
// - Them vao danh sach (vector ds)
void cListNVVP::Nhap()
{
    cout << "Nhap so luong nhan vien: ";
    cin >> soLuong;

    for (int i = 0; i < soLuong; i++)
    {
        cout << "\nNhap thong tin nhan vien thu " << i + 1 << ":\n";
        cNhanVienVP nv;
        nv.Nhap();
        ds.push_back(nv);
    }
}
// Xuat danh sach nhan vien ra man hinh
// Input: Khong co
// Output: In ra tat ca thong tin cac nhan vien
// Huong giai quyet:
// - Neu soLuong = 0 thi thong bao danh sach rong
// - Duyet danh sach va goi ham Xuat cua tung nhan vien
void cListNVVP::Xuat()
{
    if (soLuong == 0)
    {
        cout << "Danh sach rong.";
        return;
    }
    cout << "\nDanh sach nhan vien:\n";
    for (const auto& nv : ds)
    {
        nv.Xuat();
    }

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
void partition(vector<cNhanVienVP>& ds, int left, int right, int& i, int& j)
{
    if (left >= right) return;

    i = left, j = right;
    int pivot = ds[left + (right - left) / 2].getLuong();
    while (i <= j)
    {
        while (ds[i].getLuong() < pivot) i++;
        while (ds[j].getLuong() > pivot) j--;

        if (i <= j)
        {
            cNhanVienVP temp = ds[i];
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
void cListNVVP::sortLuongTangDan( int left, int right)
{
    if (left < right) 
    {
        int i, j;
        partition(ds, left, right, i, j);

        sortLuongTangDan( left, j);
        sortLuongTangDan(i, right);
    }
}

