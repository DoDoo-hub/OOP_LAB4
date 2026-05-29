#include <iostream>
#include "CDonThuc.h"
using namespace std;

CDonThuc::CDonThuc():bac(0),heso(0){}

CDonThuc::CDonThuc(int n, int a):bac(n),heso(a){}

CDonThuc::~CDonThuc(){}

ostream& operator <<(ostream& os, const CDonThuc &dt){
    //chỉ in trị tuyệt đối của hệ số, còn dấu(+/-) thì do DaThuc xử lý
    int absHeso=abs(dt.heso);

    //Nếu hệ số=0 thì không cần in đơn thức đó
    if(absHeso==0) return os;

    // 1. Xử lý phần hệ số
    if (absHeso != 1 || dt.bac == 0) {
        os << absHeso;
    }

    // 2. Xử lý phần x và bậc
    if (dt.bac>0) {
        os << "x";
        if (dt.bac > 1)
            os << "^" << dt.bac;
    }

    return os;
}

//Tính giá trị đơn thức khi biết x
long long CDonThuc::TinhGiaTri(int x){
    long long luyThua=1;
    for(int i=0;i<bac;i++)
        luyThua*=x;
    return (long long)heso * luyThua;//trả về giá trị đơn thức
}

CDonThuc CDonThuc::operator+(const CDonThuc &B) const {
    CDonThuc c;
    c.bac=B.bac; //bacC=bacB=bacA
    c.heso=this->heso+B.heso;
    return c;
}

int CDonThuc::getBac() const{return bac;}

int CDonThuc::getHeSo() const{return heso;}

void CDonThuc::setHeSo(int hs_moi){heso=hs_moi;}
