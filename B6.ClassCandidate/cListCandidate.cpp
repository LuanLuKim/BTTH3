#include "cListCandidate.h"

// Phuong thuc: nhap()
// Input: Khong co
// Output: Cac thong tin duoc luu tru trong vector danhsach
// Huong giai quyet: Nhap so luong thi sinh
//                   Dung vong lap de nhap tung thi sinh bang cach goi ham nhap() cua doi tuong cCandidate
//                   Day tung thi sinh vao vector danhSach
void cListCandidate::nhap()
{
    cout << "Nhap so luong thi sinh: ";
    cin >> soLuong;
    cin.ignore();
    for (int i = 0; i < soLuong; ++i) {
        cout << "\nNhap thong tin thi sinh thu " << i + 1 << ":\n";
        cCandidate ts;
        ts.nhap();
        danhSach.push_back(ts);
    }
}
// Phuong thuc: xuat()
// Input: Khong co
// Output: Xuat thong tin cac thi sinh ra man hinh
// Huong giai quyet: Duyet tung phan tu trong vector danhSach
//                   Goi ham xuat() cua doi tuong cCandidate de in thong tin
void cListCandidate::xuat() const
{
    for (const auto& ts : danhSach)
        ts.xuat();
}
// Phuong thuc: xuatThiSinhTren15()
// Input: Khong co
// Output: Xuat ra man hinh thong tin cac thi sinh co tong diem > 15
// Huong giai quyet: Duyet vector danhSach
//                   Neu tongDiem cua thi sinh > 15 thi goi ham xuat() de in ra
//                   Neu khong co thi thong bao khong co thi sinh
void cListCandidate::xuatThiSinhTren15() const
{
    bool find = false;
    cout << "\nCac thi sinh co tong diem > 15:\n";
    for (const auto& ts : danhSach)
        if (ts.tongDiem() > 15)
        {
            ts.xuat();
            find = true;
        }
    if (!find)
    {
        cout << "Khong co thi sinh nao co tong diem tren 15\n";
    }
}

// Phuong thuc: timThiSinhDiemCaoNhat()
// Input: Khong co
// Output: In ra thi sinh co tong diem cao nhat
// Huong giai quyet: Neu danh sach rong thi thong bao va ket thuc
//                   Duyet qua danh sach de tim thi sinh co tong diem lon nhat
//                   Goi ham xuat() cua thi sinh do de in ra thong tin
void cListCandidate::timThiSinhDiemCaoNhat() const
{
    if (danhSach.empty())
    {
        cout << "\nDanh sach rong!" << endl;
        return;
    }
    double maxTs = danhSach[0].tongDiem();
    for (int i = 1; i < soLuong; i++)
    {
        if (danhSach[i].tongDiem() > maxTs)
        {
            maxTs = danhSach[i].tongDiem();
        }
    }

    cout << "Thong tin thi sinh co tong diem cao nhat: \n";
    for (int i = 0; i < soLuong; i++)
    {
        if (danhSach[i].tongDiem() == maxTs)
            danhSach[i].xuat();
    }
}
// Ham: partition()
// Input: Mang vector ds, chi so left va right, bien tham chieu i va j
// Output: Cap nhat i va j (thong qua tham chieu)
// Huong giai quyet: Ap dung partition cua quicksort
void partition(vector<cCandidate> &ds, int left, int right, int& i, int& j)
{
    if (left >= right) return;
    int pivot = ds[left + (right - left) / 2].tongDiem();
    i = left, j = right;
    while (i <= j)
    {
        while (ds[i].tongDiem() > pivot) i++;
        while (ds[j].tongDiem() < pivot) j--;

        if (i <= j)
        {
            cCandidate temp = ds[i];
            ds[i] = ds[j];
            ds[j] = temp;
            i++, j--;
        }
    }
}
// Ham: QuickSort()
// Input: Mang vector ds, chi so left va right
// Output: Mang ds duoc sap xep theo thu tu giam dan cua tong diem
// Huong giai quyet: Ap dung quicksort
void QuickSort(vector<cCandidate> &ds, int left, int right)
{
    if (left >= right) return;
    int i, j;
    partition(ds, left, right, i, j);

    QuickSort(ds, left, j);
    QuickSort(ds, i, right);
}
// Phuong thuc: sapXepGiamDanTheoTongDiem()
// Input: Khong co
// Output: Danh sach duoc sap xep giam dan theo tong diem
// Huong giai quyet: Goi ham quicksort giam dan theo tong diem
void cListCandidate::sapXepGiamDanTheoTongDiem()
{
    if(soLuong > 0)
        QuickSort(danhSach, 0, soLuong - 1);
}
