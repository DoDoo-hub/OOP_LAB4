#include <iostream>
#include <cmath>
#include <iomanip>
#include "CDate.h"
using namespace std;

CDate::CDate(int ngay, int thang, int nam): iNgay(ngay), iThang(thang), iNam(nam){} 

CDate::~CDate() {}

bool CDate::LaNamNhuan(int nam) const { //1: năm nhuận, 0: năm thường
    return (nam%4==0 && nam%100!=0) || (nam%400==0);
}

int CDate::SoNgayTrongThang(int thang, int nam) const { //Trả về số ngày của các tháng trong năm
    switch(thang){
        case 4: case 6: case 9: case 11: return 30;
        case 2: return LaNamNhuan(nam)?29:28;
        default: return 31;
    }
}

// Đổi ngày/tháng/năm -> số ngày kể từ 01/01/0001
long long CDate::ChuyenDoiSangNgay() const {
    long long tongNgay=iNgay; 
    
    // Cộng ngày của các năm trước đó
    for(int y=1;y<iNam;y++){
        tongNgay+= LaNamNhuan(y)?366:365;
    }
    // Cộng ngày của các tháng trước đó trong năm hiện tại
    for(int m=1;m<iThang;m++){
        tongNgay+= SoNgayTrongThang(m,iNam);
    }
    return tongNgay;
}

// Chuyển ngược số ngày lại thành ngày/tháng/năm
void CDate::ChuyenSangDate(long long tongNgay){
    iNam=1;
    while(true){
        int ngayTrongNam= LaNamNhuan(iNam)?366:365;
        if(tongNgay<=ngayTrongNam) break;
        tongNgay-= ngayTrongNam;
        iNam++;
    }

    iThang=1;
    while(true){
        int ngayTrongThang= SoNgayTrongThang(iThang,iNam);
        if(tongNgay<=ngayTrongThang) break;
        tongNgay-= ngayTrongThang;
        iThang++;
    }
    iNgay= tongNgay;
}

istream& operator>>(istream& is, CDate &date){
    // Nhập năm>0
    do{
        cout<<"Nhap nam (nam>0): ";
        is>>date.iNam;
    } while(date.iNam<=0);

    //Nhập tháng(1-12)
    do{
        cout<<"Nhap thang hop le: ";
        is>>date.iThang;
    } while(1>date.iThang || date.iThang>12);

    //Nhập ngày hợp lệ dựa theo tháng và năm đã có
    cout<<"Nhap ngay hop le: ";
    is>>date.iNgay;
    while(date.iNgay<1 || date.iNgay> date.SoNgayTrongThang(date.iThang,date.iNam) ){
        cout<<"Ngay khong ton tai, hay nhap lai: ";
        is>>date.iNgay;
    }
    return is;
}

ostream& operator<<(ostream& os, const CDate &date){
    //Xuất theo định dạng dd/mm/yyyy
    os<<setfill('0')<<setw(2)<<date.iNgay<<"/"
      <<setfill('0')<<setw(2)<<date.iThang<<"/"
      <<setfill('0')<<setw(4)<<date.iNam;
    return os;
}

CDate CDate::operator+(int x){
    CDate kq;
    kq.ChuyenSangDate(this->ChuyenDoiSangNgay() + x);
    return kq;
}

CDate CDate::operator-(int x){
    CDate kq;
    kq.ChuyenSangDate(this->ChuyenDoiSangNgay() - x);
    return kq;
}

// Khoảng cách giữa 2 CDate tính bằng ngày
long long CDate::operator-(const CDate &other){
    return abs(this->ChuyenDoiSangNgay() - other.ChuyenDoiSangNgay()); 
}

// Tiền tố ++date: Tăng rồi mới trả về giá trị mới
CDate& CDate::operator++(){
    long long tiepTheo= this->ChuyenDoiSangNgay() + 1;
    this->ChuyenSangDate(tiepTheo);
    return *this;
}

// Tiền tố --date
CDate& CDate::operator--(){
    long long truocDo= this->ChuyenDoiSangNgay() - 1;
    this->ChuyenSangDate(truocDo);
    return *this;
}

// Hậu tố date++: Lưu lại giá trị cũ, tăng bản thân, rồi trả về giá trị cũ
CDate CDate::operator++(int){
    CDate temp= *this;
    long long tiepTheo= this->ChuyenDoiSangNgay() + 1;
    this->ChuyenSangDate(tiepTheo);
    return temp;
}

// Hậu tố date--
CDate CDate::operator--(int){
    CDate temp= *this;
    long long truocDo= this->ChuyenDoiSangNgay() - 1;
    this->ChuyenSangDate(truocDo);
    return temp;
}

