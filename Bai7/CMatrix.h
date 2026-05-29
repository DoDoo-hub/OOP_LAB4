#ifndef CMATRIX_H
#define CMATRIX_H
#include <iostream>
#include<vector>
#include "CVector.h"
using namespace std;

class CMatrix
{
private:
    int iDong, iCot; //iDong: số dòng, iCot: số cột
    vector<vector<double>> data; //Ma trận được lưu dưới dạng vector 2 chiều

public:
    CMatrix(int dong=0, int cot=0);
    ~CMatrix();

    // Nạp chồng toán tử nhập/xuất (friend)
    friend istream& operator>>(istream& is, CMatrix &M);
    friend ostream& operator<<(ostream& os, const CMatrix &M);

    int getDong() const;
    int getCot() const;
    
    CMatrix operator+(const CMatrix &B) const; //Trả về ma trận tổng: C= A+B
    CMatrix operator-(const CMatrix &B) const; //Trả về ma trận hiệu: C= A-B

    // Nhân ma trận với một số(giao hoán)
    CMatrix operator*(double k) const;    // C= A*k
    friend CMatrix operator*(double k, const CMatrix &M); // C= k*A 

    CMatrix TinhChuyenVi() const;  // Trả về ma trận chuyển vị của ma trận hiện tại

    //Nhân ma trận với 1 vector cột: C= A*vec 
    //(chỉ áp dụng khi số cột của matrix bằng kích thước của vector)
    CVector operator*(const CVector &V) const;

    //Trả về tích 2 matrix: C= A*B (chỉ áp dụng khi số cột A bằng số dòng B)
    CMatrix operator*(const CMatrix &other) const; 

};

#endif // CMATRIX_H



