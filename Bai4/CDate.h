#ifndef CDATE_H
#define CDATE_H
#include <iostream>
using namespace std;

class CDate {
private:
    int iNgay;
    int iThang;
    int iNam;
    // Các hàm hỗ trợ 
    bool LaNamNhuan(int nam) const; 
    int SoNgayTrongThang(int thang, int nam) const;
    long long ChuyenDoiSangNgay() const; //Đổi ngày/tháng/năm -> số ngày kể từ 01/01/0001
    void ChuyenSangDate(long long tongNgay); //Đổi từ số ngày kể từ 01/01/0001 -> ngày/tháng/năm

public:
    CDate(int ngay=1, int thang=1, int nam=1);
    ~CDate();

    // Nạp chồng toán tử nhập/xuất (friend)
    friend istream& operator>>(istream& is, CDate &date);
    friend ostream& operator<<(ostream& os, const CDate & date);

    //Nạp chồng phép toán:
    // Cộng trừ một số ngày
    CDate operator+(int x);
    CDate operator-(int x);

    // Khoảng cách giữa 2 CDate tính bằng ngày
    long long operator-(const CDate &other);

    // Tăng giảm 1 ngày (Tiền tố: ++date, --date)
    CDate& operator++();
    CDate& operator--();

    // Tăng giảm 1 ngày (Hậu tố: date++, date--)
    CDate operator++(int);
    CDate operator--(int);

};

#endif
