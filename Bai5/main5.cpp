#include <iostream>
#include <vector>
#include "CDaThuc.h"
using namespace std;

int main(){
    CDaThuc A,B;
    // Nhập
    cout<<"Nhap da thuc A:\n";
    cin>>A;
    cout<<"\nNhap da thuc B:\n";
    cin>>B;

    // Xuất
    cout<<"\nDa thuc A(x)= "<<A;
    cout<<"\nDa thuc B(x)= "<<B;

    // Tính toán

    cout<<"\n\nTinh gia tri da thuc A khi biet gia tri bien x";
    int x_a;
    cout<<"\nNhap x: "; cin>>x_a;
    cout<<"A("<<x_a<<")= "<< A(x_a); //Gọi operator() để tính giá trị của đa thức A tại x_a

    cout<<"\n\nTinh gia tri da thuc B khi biet gia tri bien x";
    int x_b;
    cout<<"\nNhap x: "; cin>>x_b;
    cout<<"B("<<x_b<<")= "<<B(x_b); //Gọi operator() để tính giá trị của đa thức B tại x_b

    cout << "\n\nTong A+B= "<< A+B;//Gọi operator+ để tính tổng A và B, trả về đa thức mới là kết quả phép cộng
    cout << "\nHieu A-B= "<< A-B;//Gọi operator- để tính hiệu A và B, trả về đa thức mới là kết quả phép trừ
    cout << "\nTich A*B= "<< A*B;//Gọi operator* để tính tích A và B, trả về đa thức mới là kết quả phép nhân

    return 0;
}
