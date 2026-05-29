#include <iostream>
#include "SoPhuc.h"
#include <cmath>
using namespace std;

//Hàm main của class SoPhuc
int main(){
    cout<<"Nhap 1 so thuc: ";
    double real; cin>>real;
    // Test "quan điểm một số thực như một số phức đặc biệt"
    SoPhuc spReal = real; // Tự động gọi SoPhuc(real, 0)
    cout<<"So thuc vua nhap: "<<spReal<<endl;

    SoPhuc a,b;
    cout<< "\nNhap so phuc A:\n";
    cin>>a;

    cout<< "\nNhap so phuc B:\n";
    cin>>b;

    cout<< "\nSo phuc A: "<< a;

    cout<< "\nSo phuc B: "<< b;

    // Tính toán
    cout << "\n\nTong: "<< a+b;
    cout << "\nHieu: "<< a-b;
    cout << "\nTich: "<< a*b;
    cout << "\nThuong: "<< a/b;

    //So sánh
    if(a==b)
        cout<<"\nSo phuc A bang so phuc B.";
    else
        cout<<"\nSo phuc A khac so phuc B.";

    return 0;
}

