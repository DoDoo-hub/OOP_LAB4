#ifndef PHANSO_H
#define PHANSO_H
#include <iostream>
using namespace std;

class PhanSo{
private:
    int iTu;
    int iMau;
public:
    PhanSo(int t=0,int m=1);
    ~PhanSo();

    void RutGon(); //Rút gọn phân số
    // Nạp chồng toán tử nhập/xuất (friend)
    friend istream& operator>>(istream& is, PhanSo &ps);
    friend ostream& operator<<(ostream& os, const PhanSo &ps);

    // Nạp chồng các toán tử số học
    PhanSo operator+(const PhanSo &ps);
    PhanSo operator-(const PhanSo &ps);
    PhanSo operator*(const PhanSo &ps);
    PhanSo operator/(const PhanSo &ps);

    // Nạp chồng các toán tử so sánh
    bool operator==(const PhanSo &ps);
    bool operator>(const PhanSo &ps);
    bool operator<(const PhanSo &ps);
};

#endif // PHANSO_H
