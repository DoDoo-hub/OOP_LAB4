#include <iostream>
#include "PhanSo.h"
using namespace std;

int UCLN(int a,int b){
    if(b==0) return a;
    return UCLN(b,a%b);
}

PhanSo::PhanSo(int t, int m): iTu(t), iMau(m){
    RutGon();
}

PhanSo::~PhanSo(){}

void PhanSo::RutGon(){
    // Chia cả tử và mẫu cho ước chung lớn nhất để rút gọn
    int ucln=UCLN(abs(iTu),abs(iMau));
    if(ucln!=0){ // Tránh chia cho 0 khi cả tử và mẫu đều là 0
        iTu/=ucln;
        iMau/=ucln;
    }

    // Đưa dấu về tử
    if (iMau<0){
        iTu=-iTu;
        iMau=-iMau;
    }
}

istream& operator>>(istream& is, PhanSo &ps){
    cout<< "Nhap tu: ";
    is>>ps.iTu;
    do{
        cout<< "Nhap mau (khac 0): ";
        is>>ps.iMau;
    }while (ps.iMau==0);
    ps.RutGon();
    return is;
}

ostream& operator<<(ostream& os, const PhanSo &ps){
    if(ps.iMau==0){ //kết quả của phép chia cho 0(không xác định)
        os<<"Khong xac dinh (Chia cho 0)";
        return os;
    }

    if(ps.iMau==1) os<<ps.iTu; // Mẫu số bằng 1-> chỉ in tử,
    else os<<ps.iTu<<"/"<<ps.iMau;
    return os;
}


PhanSo PhanSo::operator+(const PhanSo &ps){
    return PhanSo(iTu*ps.iMau + ps.iTu*iMau, iMau*ps.iMau);
}

PhanSo PhanSo::operator-(const PhanSo &ps){
    return PhanSo(iTu*ps.iMau - ps.iTu*iMau, iMau*ps.iMau);
}

PhanSo PhanSo::operator*(const PhanSo &ps){
    return PhanSo(iTu*ps.iTu, iMau*ps.iMau);

}

PhanSo PhanSo::operator/(const PhanSo &ps){
    // Phép chia=Phép nhân ps thứ nhất với nghịch đảo ps thứ 2
    return PhanSo(iTu*ps.iMau, iMau*ps.iTu);

}

bool PhanSo::operator==(const PhanSo &ps){
    // Vì luôn rút gọn nên chỉ cần so sánh tử với tử, mẫu với mẫu
    return(iTu==ps.iTu && iMau==ps.iMau);
} //Output  1: ==, 0: !=

bool PhanSo::operator>(const PhanSo &ps){
    return(iTu*ps.iMau > ps.iTu*iMau);
} //Output  1: >, 0: <=

bool PhanSo::operator<(const PhanSo &ps){
    return(iTu*ps.iMau < ps.iTu*iMau);
} //Output  1: <, 0: >=






