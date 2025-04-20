#pragma once
#include "cCandidate.h"
#include <vector>
#include <algorithm>
class cListCandidate : public cCandidate
{
private:
    vector<cCandidate> danhSach;
    int soLuong;
public:
    cListCandidate() 
    { 
        danhSach.clear(); 
        soLuong = 0; 
    }
    ~cListCandidate() {}
    void nhap();
    void xuat() const;
    void xuatThiSinhTren15() const;
    void timThiSinhDiemCaoNhat() const;
    void sapXepGiamDanTheoTongDiem();
    // Ham lay so luong
    // Input: Khong co
    // Output: So luong phan tu cua danh sach
    int getSoLuong() { return soLuong; }
};

