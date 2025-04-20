#include "PhanSo.h"
// Ham tinh uoc chung lon nhat (GCD) cua hai so nguyen a va b
// Input: 2 so nguyen a va b
// Output: UCLN cua a va b
// Xu ly: dung thuat toan Euclid de tim GCD
int gcd( int a, int b)
{
    if (a == 0 || b == 0) return a + b;
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a + b;
}
// Ham nhap phan so tu ban phim
// Input: Khong co
// Output: Khong co
// Xu ly: Dung cin de nhpa du lieu cho tu mau va dong thoi kiem tra mau so khac 0, neu bang 0 thi nhap lai
void PhanSo::Nhap() 
{
    cout << "Nhap tu so: "; cin >> tu;
    do {
        cout << "Nhap mau so (khac 0): "; cin >> mau;
        if (mau == 0)
            cout << "Mau khong duoc bang 0. Vui long nhap lai.\n";
    } while (mau == 0);
    RutGon();
}
// Ham xuat phan so ra man hinh
// Input: Khong co
// Output: Khong co
// Xu ly: Dung cout de xuat phan so, neu tu = 0 hoac mau = 1 thi chi in tu nguoc lai in tu/mau
void PhanSo::Xuat() const 
{
    cout << tu;
    if (tu == 0 || mau == 1)
        return;
    cout << '/' << mau;
}
// Ham rut gon phan so ve dang toi gian
// Input: Khong co
// Output: Khong co
// Xu ly: tim uoc chung lon nhat roi chia cho ca tu va mau
//        neu mau < 0 thi doi dau ca tu va mau
void PhanSo::RutGon() 
{
    int ucln = gcd(tu, mau);
    tu /= ucln;
    mau /= ucln;
    if (mau < 0) 
    {
        tu = -tu;
        mau = -mau;
    }
}
// Ham tra ve gia tri cua tu so
// Input: Khong co
// Output: Tu so cua phan so
int PhanSo::getTu() const 
{
    return tu;
}

// Toan tu so sanh phan so nho hon
// Input: Phan kho khac (ps)
// Output: true neu phan so hien tai nho hon ps va false neu nguoc lai
// Xu ly: So sanh bang cach nhan cheo
bool PhanSo::operator<(const PhanSo& ps) const 
{
    return tu * ps.mau < ps.tu * mau;
}
// Toan tu so sanh phan so nho hon
// Input: Phan kho khac (ps)
// Output: true neu phan so hien tai lon hon ps va false neu nguoc lai
// Xu ly: So sanh bang cach nhan cheo
bool PhanSo::operator>(const PhanSo& ps) const 
{
    return tu * ps.mau > ps.tu * mau;
}
// Toan tu cong hai phan so
// Input: Phan so khac (ps)
// Output: Phan so moi
// Xu ly: Thuc hien quy dong, sau do cong lan luot
//        tu moi = tu * ps.mau + ps.tu * mau
//        mau moi = mau * ps.mau
PhanSo PhanSo::operator+(const PhanSo& ps) const 
{
    int newTu = tu * ps.mau + ps.tu * mau;
    int newMau = mau * ps.mau;
    PhanSo c;
    c.tu = newTu;
    c.mau = newMau;
    return c;
}
