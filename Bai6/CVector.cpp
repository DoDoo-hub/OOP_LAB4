#include "CVector.h"
#include <cmath>
const double PI = 3.14159265358979323846;

//Khởi tạo vector có sochieu chiều, tất cả tọa độ ban đầu = 0
CVector::CVector(int sochieu): SoChieu(sochieu), ToaDo(sochieu,0.0){}

CVector::~CVector(){}

istream& operator>>(istream& is, CVector &V){
    cout<< "Nhap so chieu cua vector: ";
    is>>V.SoChieu;
    V.ToaDo.resize(V.SoChieu);
    for(int i=0;i<V.SoChieu;i++){
        cout<<"Nhap toa do thu "<<i+1<<": ";
        is>>V.ToaDo[i];
    }
    return is;
}

ostream& operator<<(ostream& os, const CVector &V){
    os<<"(";
    for(int i=0;i<V.SoChieu;i++){
        os<<V.ToaDo[i];
        if(i!=V.SoChieu-1) os<<"; ";
    }
    os<<")";
    return os;
}

//trả về 1 vector mới là tổng của 2 vector
CVector CVector::operator+(const CVector &other) const{
    if(this->SoChieu != other.SoChieu){
        cout<< "\nLoi: Khong the cong 2 vector khac so chieu!";
        return CVector(0); //Trả về vector rỗng
    }

    CVector kq(this->SoChieu);
    for(int i=0;i<this->SoChieu;i++){
        kq.ToaDo[i]= this->ToaDo[i] + other.ToaDo[i];
    }
    return kq;
}

//trả về 1 vector mới là hiệu của 2 vector
CVector CVector::operator-(const CVector &other) const{
    if(this->SoChieu != other.SoChieu){
        cout<< "\nLoi: Khong the tru 2 vector khac so chieu!";
        return CVector(0); //Trả về vector rỗng
    }

    CVector kq(this->SoChieu);
    for(int i=0;i<this->SoChieu;i++){
        kq.ToaDo[i]= this->ToaDo[i] - other.ToaDo[i];
    }
    return kq;
}

int CVector::getSoChieu() const {return this->SoChieu;}

int CVector::getToaDo(int index) const {return this->ToaDo[index];}

void CVector::setToaDo(int index, double value) {this->ToaDo[index] = value;}

//Trả về tích của 1 vector với 1 số k
CVector CVector::operator*(double k) const{
    CVector kq(this->SoChieu);
    for(int i=0;i<this->SoChieu;i++){
        kq.ToaDo[i]= this->ToaDo[i] * k;
    }
    return kq;
}

//Trả về tích của k với 1 vector (để hỗ trợ tính giao hoán: v*k và k*v)
CVector operator*(double k, const CVector &V){
    return V*k; //Tận dụng vector*k đã có sẵn ở trên
}

//Trả về 1 số thực là tích vô hướng của 2 vector
double CVector::operator*(const CVector &other) const{
    if(this->SoChieu != other.SoChieu){
        cout<< "\nLoi: Khong the tinh tich vo huong 2 vector khac so chieu!";
        return NAN; //Trả về giá trị "Không xác định" NaN (Not a Number)
    }

    double tichVoHuong=0.0;
    for(int i=0;i<this->SoChieu;i++){
        tichVoHuong+= this->ToaDo[i] * other.ToaDo[i];
    }
    return tichVoHuong;
}

//Trả về độ dài của vector
//Độ dài của 1 vector = căn bậc hai của tích vô hướng vector đó với chính nó
double CVector::TinhDoDai() const{
    return sqrt(this->operator*(*this));
}

double CVector::TinhKhoangCach(const CVector &other){
    if(this->SoChieu != other.SoChieu){
        cout<< "\nLoi: Khong the tinh khoang cach 2 vector khac so chieu!";
        return -1.0;  //Trả về -1 để báo lỗi
    }
    CVector hieu = *this - other;  //Khoảng cách giữa 2 vector = độ dài của hiệu 2 vector đó
    return hieu.TinhDoDai();
}

//Trả về góc giữa 2 vector nằm trong khoảng [0, 180] độ
//Góc giữa 2 vector = arccos(tích vô hướng của 2 vector / (độ dài vector 1 * độ dài vector 2))
double CVector::TinhGoc(const CVector &other){
    if(this->SoChieu != other.SoChieu){
        cout<< "\nLoi: Khong the tinh goc 2 vector khac so chieu!";
        return -1.0; //Trả về -1 để báo lỗi
    }
    double tichVoHuong= *this * other;
    double doDai1= this->TinhDoDai();
    double doDai2= other.TinhDoDai();

    if(doDai1==0 || doDai2==0){
        cout<< "\nLoi: Khong the tinh goc voi vector co do dai bang 0!";
        return -1.0; //Trả về -1 để báo lỗi
    }

    double cosGoc = tichVoHuong / (doDai1 * doDai2);
    //Giới hạn giá trị của cosGoc trong khoảng [-1, 1] để tránh lỗi khi tính acos
    if(cosGoc > 1) cosGoc= 1;
    if(cosGoc < -1) cosGoc= -1;

    return acos(cosGoc) * 180.0 / PI; //Chuyển từ radian sang độ
}
