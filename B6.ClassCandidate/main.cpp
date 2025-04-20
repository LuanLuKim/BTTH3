#include <iostream>
#include "cListCandidate.h"

using namespace std;

int main() 
{
    cListCandidate danhSach;
    danhSach.nhap();
    if (danhSach.getSoLuong() != 0)
    {
        danhSach.xuat();
        danhSach.xuatThiSinhTren15();
        danhSach.timThiSinhDiemCaoNhat();

        cout << "\nDanh sach thi sinh sau khi sap xep giam dan theo tong diem: \n";
        danhSach.sapXepGiamDanTheoTongDiem();
        danhSach.xuat();
        return 0;
    }
    else
        cout << "Danh sach rong.";
    return 0;
}
