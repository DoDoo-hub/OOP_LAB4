#include <iostream>
#include "SoPhuc.h"
#include <cmath>
using namespace std;


SoPhuc::SoPhuc(double t, double a): iThuc(t), iAo(a){}

SoPhuc::~SoPhuc(){}

istream& operator>>(istream& is, SoPhuc &sp){
    cout<< "Nhap phan thuc: ";
    is>>sp.iThuc;
    cout<< "Nhap phan ao: ";
    is>>sp.iAo;
    return is;
}

ostream& operator<<(ostream& os, const SoPhuc &sp){
    if(sp.iThuc==0 && sp.iAo==0) os<<0; // cả phần thực và ảo đều=0 =>số phức=0

    if(isnan(sp.iThuc) && isnan(sp.iAo)){ // kết quả của phép chia cho 0(không xác định)
        os<< "Khong xac dinh (Chia cho 0)";
        return os;
    }

    //Định dạng lại cách in
    if(sp.iThuc!=0)
        os<<sp.iThuc;
    if(sp.iAo!=0){
        if(sp.iThuc!=0){
            os<< (sp.iAo<0?" - ":" + ");
            os<< abs(sp.iAo);
        }
        else os<< sp.iAo;

        os<<"i";
    }
    return os;
}

SoPhuc SoPhuc::operator+(const SoPhuc &sp){
    return SoPhuc(iThuc + sp.iThuc, iAo + sp.iAo);
}

SoPhuc SoPhuc::operator-(const SoPhuc &sp){
    return SoPhuc(iThuc - sp.iThuc, iAo - sp.iAo);
}

SoPhuc SoPhuc::operator*(const SoPhuc &sp){
    SoPhuc kq;
    //Sau khi nhân phân phối và thay i*i=-1 thì ta có kết quả:
    kq.iThuc= iThuc*sp.iThuc - iAo*sp.iAo;
    kq.iAo= iThuc*sp.iAo + iAo*sp.iThuc;
    return kq;
}

SoPhuc SoPhuc::operator/(const SoPhuc &sp){
    SoPhuc kq;
    //Chia 2 số phức: nhân cả tử và mẫu với số phức liên hợp của mẫu số, ta có kết quả:
    double mau= sp.iThuc*sp.iThuc + sp.iAo*sp.iAo;
    if(mau==0){  // Trường hợp chia cho 0, gán kq= giá trị "Không xác định" NaN (Not a Number)
        kq.iThuc=NAN;
        kq.iAo=NAN;
        return kq;
    }

    kq.iThuc= (iThuc*sp.iThuc + iAo*sp.iAo) / mau;
    kq.iAo= (iAo*sp.iThuc - iThuc*sp.iAo) / mau;
    return kq;
}

bool SoPhuc::operator==(const SoPhuc &sp){
    return (iThuc == sp.iThuc && iAo == sp.iAo);
}

bool SoPhuc::operator!=(const SoPhuc &sp){
    return !(*this == sp);
}


