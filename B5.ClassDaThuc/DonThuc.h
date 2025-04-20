#pragma once
class DonThuc
{
protected:
    float heSo;
    int soMu;

public:
    // Ham khoi tao khong doi
    // Input: Khong co
    // Output: Tao don thuc voi he so = so mu = 0
    DonThuc() { heSo = soMu = 0; }
    // Ham khoi tao co doi
    // Input: 2 so hs va sm
    // Output: Tao don thuc voi he so = hs va so mu = sm
    DonThuc(float hs, int sm) : heSo(hs), soMu(sm) {}

    ~DonThuc(){}

    // Ham lay he so
    // Input: Khong co
    // Output: Gia tri cua he so
    float getHeSo() const { return heSo; }
    // Ham lay so mu
    // Input: Khong co
    // Output: Gia tri cua so mu
    int getSoMu() const { return soMu; }
    // Ham doi he so
    // Input: 1 so thuc hs
    // Output: Thay doi he so = hs
    void setHeSo(float hs) { heSo = hs; }
    // Ham doi so mu
    // Input: 1 so thuc sm
    // Output: Thay doi so mu = sm
    void setSoMu(int sm) {soMu = sm; }

    float tinhGiaTri(float x) const;
    void xuat() const;
};

