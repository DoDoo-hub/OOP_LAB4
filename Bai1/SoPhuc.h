#ifndef SOPHUC_H
#define SOPHUC_H
#include <iostream>
using namespace std;

class SoPhuc { 
private:
    double iThuc;
    double iAo;
public:
    // Phương thức thiết lập duy nhất với tham số mặc định
    SoPhuc(double t=0, double a=0);
    ~SoPhuc();

    // Nạp chồng toán tử nhập/xuất (friend)
    friend istream& operator >>(istream& is, SoPhuc &sp);
    friend ostream& operator <<(ostream& os, const SoPhuc &sp);

    // Nạp chồng các toán tử số học
    SoPhuc operator+(const SoPhuc &sp);
    SoPhuc operator-(const SoPhuc &sp);
    SoPhuc operator*(const SoPhuc &sp);
    SoPhuc operator/(const SoPhuc &sp);

    // Nạp chồng các toán tử so sánh
    bool operator==(const SoPhuc &sp);
    bool operator!=(const SoPhuc &sp);

};

#endif // SOPHUC_H
