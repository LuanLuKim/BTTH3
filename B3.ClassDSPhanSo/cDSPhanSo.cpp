#include "cDSPhanSo.h"

// Ham kiem tra xem mot so nguyen co phai la so nguyen to hay khong
// Input: Mot so nguyen n
// Output: True neu n la so nguyen to, nguoc lai tra ve false
// Xu ly: Neu n < 2 thi khong la so nguyen to. Duyet tu 2 den can bac hai cua n,
//        neu ton tai uoc nao thi khong phai so nguyen to
bool laNguyenTo(int n)
{
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}
// Ham nhap danh sach phan so
// Input: Khong co
// Output: Khong co
// Xu ly: Cap phat mang dong co n phan so. Goi ham Nhap cua tung phan so trong danh sach
void cDSPhanSo::Nhap() 
{
    cout << "Nhap so luong phan so: ";
    cin >> n;
    if (n == 0)
    {
        cout << "Danh sach rong.";
        return;
    }
    ds = new PhanSo[n];
    for (int i = 0; i < n; ++i) 
    {
        cout << "Phan so thu " << i + 1 << ":\n";
        ds[i].Nhap();
    }
}
// Ham xuat danh sach cac phan so ra man hinh
// Input: Khong co
// Output: Khong co
// Xu ly: Duyet mang ds va goi ham Xuat cua tung phan so
void cDSPhanSo::Xuat() const 
{
    for (int i = 0; i < n; i++)
    {
        ds[i].Xuat();
        cout << ' ';
    }
    cout << endl;
}
// Ham tinh tong tat ca phan so trong danh sach
// Input: Khong co
// Output: Tra ve phan so tong cua danh sach (da rut gon)
// Xu ly: Cong tung phan so vao bien tong bang toan tu +. Sau khi cong thi rut gon
PhanSo cDSPhanSo::TinhTong() const 
{
    PhanSo tong;
    for (int i = 0; i < n; i++)
    {
        tong = tong + ds[i];
    }
    tong.RutGon();
    return tong;
}
// Ham tim phan so lon nhat trong danh sach
// Input: Khong co
// Output: Tra ve phan so lon nhat 
// Xu ly: Khoi tao max bang phan so dau tien, duyet va so sanh cac phan so con lai
PhanSo cDSPhanSo::PhanSoMax() const 
{
    PhanSo maxPS = ds[0];
    for (int i = 1; i < n; ++i) {
        if (ds[i] > maxPS) {
            maxPS = ds[i];
        }
    }
    return maxPS;
}
// Ham tim phan so nho nhat trong danh sach
// Input: Khong co
// Output: Tra ve phan so nho nhat
// Xu ly: Khoi tao min bang phan so dau tien, duyet va so sanh cac phan so con lai
PhanSo cDSPhanSo::PhanSoMin() const
{
    PhanSo minPS = ds[0];
    for (int i = 1; i < n; ++i) 
    {
        if (ds[i] < minPS) 
        {
            minPS = ds[i];
        }
    }
    return minPS;
}
// Ham sap xep danh sach phan so theo thu tu tang dan
// Input: Chi so left va right chi dinh doan can sap xep
// Output: Khong co
// Xu ly: Su dung thuat toan quicksort voi phan hoach dua tren toan tu <
void cDSPhanSo::SapXepTang(int left, int right)
{
    if (left < right)
    {
        int i = left, j = right;
        PhanSo pivot = ds[(left + right) / 2];

        while (i <= j)
        {
            while (ds[i] < pivot) i++;
            while (ds[j] > pivot) j--;

            if (i <= j)
            {
                PhanSo temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
                i++;
                j--;
            }
        }
        if (left < j) SapXepTang(left, j);
        if (i < right) SapXepTang(i, right);
    }
}
// Ham sap xep danh sach phan so theo thu tu giam dan
// Input: Chi so left va right chi dinh doan can sap xep
// Output: Khong co
// Xu ly: Su dung thuat toan quicksort voi phan hoach dua tren toan tu >
void cDSPhanSo::SapXepGiam(int left, int right)
{
    if (left < right)
    {
        int i = left, j = right;
        PhanSo pivot = ds[(left + right) / 2];

        while (i <= j)
        {
            while (ds[i] > pivot) i++;
            while (ds[j] < pivot) j--;

            if (i <= j)
            {
                PhanSo temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
                i++;
                j--;
            }
        }
        if (left < j) SapXepGiam(left, j);
        if (i < right) SapXepGiam(i, right);
    }
}
// Ham tim phan so co tu la so nguyen to va co gia tri lon nhat
// Input: Khong co
// Output: Tra ve phan so co tu nguyen to lon nhat (neu khong co thi phan so 0)
// Xu ly: Duyet danh sach, kiem tra tu so la so nguyen to. Neu dung thi so sanh de lay lon nhat
PhanSo cDSPhanSo::PhanSoTuNTMax() const
{
    PhanSo maxTuNT;
    bool found = false;
    for (int i = 0; i<n; i++) 
    {
        if (laNguyenTo(ds[i].getTu()))
        {
            if (!found || ds[i] > maxTuNT)
            {
                maxTuNT = ds[i];
                found = true;
            }
        }
    }
    return maxTuNT;
}