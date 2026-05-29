#ifndef CVECTOR_H
#define CVECTOR_H
#include <iostream>
#include <vector>
using namespace std;

class CVector
{
private:
    int SoChieu;
    vector<double> ToaDo;
public:
    CVector(int sochieu=0);
    ~CVector();

    // Nạp chồng toán tử nhập/xuất (friend)
    friend istream& operator>>(istream& is, CVector &V);
    friend ostream& operator<<(ostream& os, const CVector &V);

    int getSoChieu() const; //Trả về số chiều của vector
    int getToaDo(int index) const; //Trả về tọa độ tại vị trí index (index bắt đầu từ 0)
    void setToaDo(int index, double value); //Đặt lại giá trị tọa độ tại vị trí index (index bắt đầu từ 0)

    //Nạp chồng các phép toán
    CVector operator+(const CVector &other) const;
    CVector operator-(const CVector &other) const;

    CVector operator*(double k) const; //Nhân vector với 1 số k
    //Nhân 1 số k với vector(để hỗ trợ tính giao hoán: v*k và k*v)
    friend CVector operator*(double k, const CVector &V);

    double operator*(const CVector &other) const; //Tích vô hướng của 2 vector

    double TinhDoDai() const; //Trả về độ dài của vector
    double TinhKhoangCach(const CVector &other); //Trả về khoảng cách giữa 2 vector
    double TinhGoc(const CVector &other); //Trả về góc giữa 2 vector (đơn vị: độ)
};

#endif // CVECTOR_H
