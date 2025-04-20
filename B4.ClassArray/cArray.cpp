#include "cArray.h"
bool cArray::prime[4000] = { true };
bool cArray::daSang = false;

// Ham sang Eratosthenes de danh dau cac so nguyen to tu 0 den 4000
// Input: Khong co
// Output: Cap nhat mang prime[], prime[i] = true neu i la so nguyen to
// Huong giai quyet: Dung thuat toan Sieve of Eratosthenes de loai bo cac boi cua so nguyen to
void cArray::sang()
{
    prime[0] = prime[1] = false;
    for (int i = 2; i*i <=4000; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= 4000; j += i)
                prime[j] = false;
        }
    }
}
// Ham khoi tao, nhap kich thuoc va cap phat dong mang a[]
// Input: Nhap tu ban phim
// Output: Mang a duoc cap phat
// Huong giai quyet: Dung new[] de cap phat dong theo kich thuoc n
cArray::cArray() 
{
    cout << "Nhap kich thuoc cho mang: "; cin >> n;
    a = new int[n];
}
// Ham huy, giai phong mang da cap phat
// Input: Khong co
// Output: Khong co
// Huong giai quyet: Dung delete[] de giai phong mang da cap phat
cArray::~cArray() 
{
    delete[] a;
}

// Sinh ngau nhien cac gia tri cho mang a[]
// Input: Khong co
// Output: Mang a chua cac so ngau nhien
// Huong giai quyet: dung rand() sinh so ngau nhien trong khong [-4000,3999]
void cArray::generateRandom()
{
    srand(time(NULL));
    for (int i = 0; i < n; i++) 
    {
        a[i] = (rand() % 8000)-4000 ;
    }
}
// Xuat cac phan tu cua mang ra man hinh
// Input: Khong co
// Output: Khong co
// Huong giai quyet: Duyet mang va in ra tung phan tu
void cArray::Xuat() const 
{
    for (int i = 0; i < n; i++) 
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Dem so lan xuat hien cua gia tri x trong mang
// Input: Gia tri x
// Output: So lan xuat hien cua x
// Huong giai quyet: Duyet mang, tang bien dem neu gap phan tu bang x
int cArray:: count(int x) const
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x) cnt++;
    }
    return cnt;
}
// Kiem tra mang co tang dan khong
// Input: Khong co
// Output: Neu tang dan thi true, nguoc lai thi false
// Huong giai quyet: Kiem tra a[i] > a[i+1], neu co thi tra ve false
bool cArray::isAscending() const
{
    for (int i = 0; i < n-1; i++)
    {
        if (a[i] > a[i + 1]) return false;
    }
    return true;
}
// Tim phan tu le nho nhat trong mang
// Input: Khong co
// Output: Con tro den phan tu le nho nhat, NULL neu khong co
// Huong giai quyet: Duyet mang, cap nhat con tro Min khi gap so le nho hon
int* cArray:: minOdd() const
{
    int* Min = NULL;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0 && Min == NULL)
            Min = &a[i];
        else if (a[i] % 2 != 0 && Min != NULL && a[i] < *Min)
            Min = &a[i];
    }
    return Min;
}

// Tim so nguyen to lon nhat trong mang
// Input: Khong co
// Output: So nguyen to lon nhat, -1 neu khong co
// Huong giai quyet: dung mang prime[] da sang, duyet mang a va tim gia tri lon nhat thoa prime[a[i]]
int cArray::maxPrime() const 
{
    if (!daSang)
    {
        sang();
        daSang = true;
    }

    int max = -1;
    for (int i = 0; i < n; i++) 
    {
        if (a[i] > 0 && prime[a[i]] && a[i] > max)
            max = a[i];
    }
    return max;
}
// Ham partition dung trong quicksort, ho tro sap xep tang/giam
// Input: Mang a, left, right, mode (0: tang, 1: giam)
// Output: Chi so i, j thong qua tham chieu sau khi chia mang
// Huong giai quyet: chon pivot o giua, dua cac phan tu < pivot ve ben trai, > pivot ve ben phai (theo mode)
void partition(int* a, int left, int right, bool mode, int &i, int &j)
{
    if (left >= right) return;
    int pivot = a[(left + right) / 2];
    i = left, j = right;
    while (i <= j)
    {
        while ((!mode && a[i] < pivot) || (mode && a[i] > pivot)) i++;
        while ((!mode && a[j] > pivot) || (mode && a[j] < pivot)) j--;

        if (i <= j)
        {
            swap(a[i], a[j]);
            i++; j--;
        }
    }
}
// Sap xep tang dan
// Input: Chi so left, right
// Output: Mang duoc sap xep tang dan
// Huong giai quyet: Dung thuat toan quicksort de sap xep tang dan
void cArray::sortAsc(int left, int right) 
{
    if (left < right) 
    {
        int i, j;
        partition(a, left, right, 0, i, j);
        sortAsc(left, j);
        sortAsc(i, right);
    }
}
// Sap xep giam dan
// Input: Chi so left, right
// Output: Mang duoc sap xep giam dan
// Huong giai quyet: Dung thuat toan quicksort de sap xep giam dan
void cArray::sortDesc(int left, int right)
{
    if (left < right)
    {
        int i, j;
        partition(a, left, right, 1, i, j);
        sortDesc(left, j);
        sortDesc(i, right);
    }
}