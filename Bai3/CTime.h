#ifndef CTIME_H
#define CTIME_H
#include <iostream>
using namespace std;

class CTime{
private:
    int iGio;
    int iPhut;
    int iGiay;
    void ChuanHoa(); //Hàm nội bộ để đưa giờ, phút, giây về đúng khoảng [0..23]:[0..59]:[0..59]
public:
    CTime(int gio=0, int phut=0, int giay=0);
    ~CTime();

    //Nạp chồng nhập/xuất
    friend istream& operator>>(istream& is, CTime &t);
    friend ostream& operator<<(ostream& os, const CTime &t);

    //Nạp chồng phép toán
    // Cộng trừ một số nguyên giây
    CTime operator+(int x);
    CTime operator-(int x);

    // Tăng giảm 1 giây (Tiền tố: ++t, --t)
    CTime& operator++();
    CTime& operator--();

    // Tăng giảm 1 giây (Hậu tố: t++, t--)
    CTime operator++(int);
    CTime operator--(int);

};

#endif // CTIME_H
