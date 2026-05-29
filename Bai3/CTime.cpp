#include <iostream>
#include <iomanip>
#include "CTime.h"
using namespace std;

CTime::CTime(int gio, int phut, int giay): iGio(gio), iPhut(phut), iGiay(giay){
    ChuanHoa();
}

CTime::~CTime(){}

void CTime::ChuanHoa(){
    // Quy đổi hết ra tổng số giây
    long long tongGiay=(long long)iGio*3600 + iPhut*60 + iGiay;

    // Xử lý nếu tổng giây bị âm (khi trừ quá nhiều), hoặc số giây nhiều hơn số giây 1 ngày(24*3600 s)
    long long motNgay= 24*3600;
    tongGiay= (tongGiay%motNgay + motNgay) % motNgay;//Cách này sẽ đảm bảo tongGiay luôn nằm trong khoảng [0...86400-1] dù tongGiay ban đầu là âm hay dương lớn hơn 1 ngày
    
    iGio= tongGiay/3600;  tongGiay=tongGiay%3600;
    iPhut= tongGiay/60;
    iGiay= tongGiay%60;
}

istream& operator>>(istream& is, CTime &t){
    // giophutgiay lớn nhất là: 23:59:59, thêm 1s nữa sẽ là 00:00:00 của ngày mới
    //Định dạng theo đồng hồ điện tử
    do{
        cout<<"Nhap gio hop le: ";
        is>>t.iGio;
    } while(0>t.iGio || t.iGio>23);

    do{
        cout<<"Nhap phut hop le: ";
        is>>t.iPhut;
    } while(0>t.iPhut || t.iPhut>59);

    do{
        cout<<"Nhap giay hop le: ";
        is>>t.iGiay;
    } while(0>t.iGiay || t.iGiay>59);

    return is;
}

ostream& operator<<(ostream& os, const CTime &t){
    // Định dạng in ra luôn có 2 chữ số (vd: 12:05:00)
    os<<setfill('0')<<setw(2)<<t.iGio<<":"
      <<setfill('0')<<setw(2)<<t.iPhut<<":"
      <<setfill('0')<<setw(2)<<t.iGiay;
    return os;
}

CTime CTime::operator+(int x){
    return CTime(iGio, iPhut, iGiay+x); //Tận dụng constructor có gọi chuẩn hóa
}

CTime CTime::operator-(int x){
    return CTime(iGio, iPhut, iGiay-x);
}

// Tiền tố ++t: Tăng rồi mới trả về giá trị mới
CTime& CTime::operator++(){
    iGiay++;
    ChuanHoa();
    return *this;
}

// Tiền tố --t
CTime& CTime::operator--(){
    iGiay--;
    ChuanHoa();
    return *this;
}

// Hậu tố t++: Lưu lại giá trị cũ, tăng bản thân, rồi trả về giá trị cũ
CTime CTime::operator++(int){
    CTime temp= *this;
    iGiay++;
    ChuanHoa();
    return temp;
}

// Hậu tố t--
CTime CTime::operator--(int){
    CTime temp= *this;
    iGiay--;
    ChuanHoa();
    return temp;
}


