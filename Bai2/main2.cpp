#include <iostream>
#include "PhanSo.h"
using namespace std;

int main(){
    cout<<"Nhap 1 so nguyen: ";
    int integer; cin>>integer;
    // Test "một số nguyên như một phân số đặc biệt (mẫu số bằng 1)"
    PhanSo psInteger = integer; // Tự động gọi PhanSo(integer, 1)
    cout<<"So nguyen vua nhap: "<<psInteger<<endl;

    PhanSo a,b;
    cout << "Nhap phan so A:\n";
    cin>>a;

    cout << "Nhap phan so B:\n";
    cin>>b;

    cout << "\nPhan so A: "<<a;
    cout << "\nPhan so B: "<<b;

    // Tính toán
    cout << "\n\nTong: "<<a+b;
    cout << "\nHieu: "<<a-b;
    cout << "\nTich: "<<a*b;
    cout << "\nThuong: "<<a/b;

    // So sánh
    cout<< "\nSo sanh: ";
    if (a==b)
        cout << "A = B";
    else if (a > b)
        cout << "A > B";
    else
        cout << "A < B";

    return 0;
}
