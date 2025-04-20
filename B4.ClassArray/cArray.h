#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
class cArray
{
private:
    int* a;
    int n;

    static bool prime[4000];
    static bool daSang;
    static void sang();
public:
    cArray();
    ~cArray();

    void generateRandom();
    void Xuat() const;
    int count(int x) const;
    bool isAscending() const;
    int* minOdd() const;
    int maxPrime() const;
    void sortAsc(int left, int right);
    void sortDesc(int left, int right);
    // Ham lay kich thich mang
    // Input: Khong co
    // Output: 1 so nguyen dai dien cho kich thuoc mang
    // Huong giai quyet: Tra ve kich thuoc mang da duoc nhap truoc do
    int size() { return n; }
};

