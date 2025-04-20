#include "cDaThuc.h"
// Ham khoi tao sao chep
// Input: Mot doi tuong da thuc other
// Output: Tao doi tuong moi sao chep cac don thuc cua other
// Huong giai quyet: Cap phat mang moi va sao chep tung don thuc trong other sang doi tuong hien tai
cDaThuc::cDaThuc(const cDaThuc& other) 
{
    soLuong = other.soLuong;
    dt = new DonThuc[soLuong];
    for (int i = 0; i < soLuong; ++i) 
        dt[i] = other.dt[i];
}
// Toan tu gan
// Input: Mot doi tuong da thuc other
// Output: Gan cac gia tri va don thuc cua other cho doi tuong hien tai
// Huong giai quyet: Neu khong tu gan thi xoa mang cu cap phat lai mang moi va sao chep tung don thuc tu other
cDaThuc& cDaThuc::operator=(const cDaThuc& other) 
{
    if (this == &other) return *this;

    delete[] dt;

    soLuong = other.soLuong;
    dt = new DonThuc[soLuong];
    for (int i = 0; i < soLuong; ++i)
        dt[i] = other.dt[i];
    return *this;
}
// Ham nhap da thuc
// Input: So luong don thuc va tung he so so mu cua don thuc do tu ban phim
// Output: Mang cac don thuc duoc cap phat va luu vao doi tuong hien tai
// Huong giai quyet: Xoa mang cu neu co sau do cap phat mang moi roi lan luot nhap cac don thuc thong qua phuong thuoc nhap cua don thuc
void cDaThuc::nhap() 
{
    delete[] dt;
    cout << "Nhap so don thuc: ";
    cin >> soLuong;
    dt = new DonThuc[soLuong];

    for (int i = 0; i < soLuong; i++) 
    {
        float hs;
        int sm;
        cout << "Nhap he so va so mu cua don thuc thu " << i + 1 << ": ";
        cin >> hs >> sm;
        dt[i] = DonThuc(hs, sm);
    }
}
// Ham xuat da thuc ra man hinh
// Input: Khong co
// Output: In ra bieu thuc da thuc theo dinh dang toan hoc
// Huong giai quyet: Bo qua don thuc co he so bang 0.
//                   Don thuc dau tien xuat binh thuong thong qua phuong thuc xuat cua don thuc va cac dau cong tru theo chuan
void cDaThuc::xuat() const 
{
    bool first = true;
    for (int i = 0; i < soLuong; i++) 
    {
        if (dt[i].getHeSo() == 0) continue;

        if (first)
        {
            first = false;
            dt[i].xuat();
        }
        else
        {
            if (dt[i].getHeSo() > 0)
                cout << '+';
            dt[i].xuat();
        }
    }
    if (first) cout << 0;
    cout << endl;
}
// Ham tinh gia tri cua da thuc tai x
// Input: Gia tri x la so thuc
// Output: Gia tri cua da thuc sau khi thay x vao
// Huong giai quyet: Duyet tung don thuc tinh gia tri tai x roi cong vao bien tong
float cDaThuc::tinhGiaTri(float x) const {
    float tong = 0;
    for (int i = 0; i < soLuong; i++) {
        tong += dt[i].tinhGiaTri(x);
    }
    return tong;
}
// Toan tu cong hai da thuc
// Input: Doi tuong da thuc b
// Output: Doi tuong da thuc moi la tong cua hai da thuc
// Huong giai quyet: Duyet dong thoi hai mang don thuc gop chung cac don thuc co cung so mu va cong he so con lai giu nguyen.
//                   Sau do cat bo don thuc co he so bang 0
cDaThuc cDaThuc:: operator +(const cDaThuc& b) const
{
    cDaThuc tong;
    tong.soLuong = soLuong + b.soLuong;
    tong.dt = new DonThuc[tong.soLuong];

    int idx = 0, i = 0, j = 0;

    while (i < soLuong && j < b.soLuong)
    {
        if (dt[i].getSoMu() > b.dt[j].getSoMu())
            tong.dt[idx++] = dt[i++];
        else if (dt[i].getSoMu() < b.dt[j].getSoMu())
            tong.dt[idx++] = b.dt[j++];
        else
        {
            float hs = dt[i].getHeSo() + b.dt[j].getHeSo();
            tong.dt[idx++] = DonThuc(hs, dt[i].getSoMu());
            i++, j++;
        }
    }

    while (i < soLuong)
        tong.dt[idx++] = dt[i++];
    while (j < b.soLuong)
        tong.dt[idx++] = DonThuc(b.dt[j++]);

    tong.soLuong = idx;
    return tong;
}
// Toan tu tru hai da thuc
// Input: Doi tuong da thuc b
// Output: Doi tuong da thuc moi la hieu cua hai da thuc
// Huong giai quyet: Duyet dong thoi hai mang don thuc gop chung cac don thuc co cung so mu va tru he so.
//                   Neu khac so mu thi giu nguyen hoac doi dau tuong ung.
//                   Cuoi cung cat bo don thuc co he so bang 0
cDaThuc cDaThuc:: operator -(const cDaThuc& b) const
{
    cDaThuc hieu;
    hieu.soLuong = soLuong + b.soLuong;
    hieu.dt = new DonThuc[hieu.soLuong];

    int idx = 0, i = 0, j = 0;

    while (i < soLuong && j < b.soLuong)
    {
        if (dt[i].getSoMu() > b.dt[j].getSoMu())
            hieu.dt[idx++] = dt[i++];
        else if (dt[i].getSoMu() < b.dt[j].getSoMu())
        {
            hieu.dt[idx++] = DonThuc(-b.dt[j++].getHeSo(), b.dt[j - 1].getSoMu());
        }
        else
        {
            float hs = dt[i].getHeSo() - b.dt[j].getHeSo();
            hieu.dt[idx++] = DonThuc(hs, dt[i].getSoMu());
            i++, j++;
        }
    }

    while (i < soLuong)
        hieu.dt[idx++] = dt[i++];
    while (j < b.soLuong)
        hieu.dt[idx++] = DonThuc(-b.dt[j].getHeSo(), b.dt[j++].getSoMu());

    hieu.soLuong = idx;
    return hieu;
}