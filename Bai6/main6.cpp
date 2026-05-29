#include <iostream>
#include "CVector.h"
#include <cmath>
using namespace std;

int main(){
    CVector v1, v2;
    cout<< "Nhap vector thu nhat:\n";
    cin>>v1;
    cout<< "\nNhap vector thu hai:\n";
    cin>>v2;

    cout<< "\nVector v1: "<<v1;
    cout<< "\nVector v2: "<<v2<<"\n";

    //Test cộng 2 vector
    CVector Tong=v1+v2;
    if(Tong.getSoChieu()!=0){
        cout<< "\nv1 + v2 = "<<Tong;
    }

    //Test trừ 2 vector
    CVector Hieu=v1-v2;
    if(Hieu.getSoChieu()!=0){
        cout<< "\nv1 - v2 = "<<Hieu;
    }

    //Test nhân vector với một số k
    double k;
    cout<< "\n\nNhap so k de nhan voi v1: ";
    cin>>k;
    cout<< "v1 * "<<k<<" = "<< v1*k;
    cout<< "\nNhap so k de nhan voi v2: ";
    cin>>k;
    cout<< "v2 * "<<k<<" = "<< k*v2<<"\n";

    //Test tích vô hướng của 2 vector
    double TichVoHuong=v1*v2;
    if(!isnan(TichVoHuong)){
        cout<< "\nv1 * v2 (tich vo huong) = "<< TichVoHuong;
    }

    //Test độ dài của vector
    cout<< "\n\nDo dai cua v1: "<< v1.TinhDoDai();
    cout<< "\nDo dai cua v2: "<< v2.TinhDoDai()<<"\n";

    //Test khoảng cách và góc giữa 2 vector
    double khoangcach= v1.TinhKhoangCach(v2);
    if(khoangcach != -1.0)
        cout<< "\nKhoang cach giua v1 va v2: "<< khoangcach;
    double Goc= v1.TinhGoc(v2);
    if(Goc != -1.0){ //Nếu trả về -1.0 thì có lỗi khi tính góc 
        cout<< "\nGoc giua v1 va v2: "<< Goc << " do";
    }

    return 0;
}
