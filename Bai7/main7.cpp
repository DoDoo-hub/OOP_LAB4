#include <iostream>
#include "CMatrix.h"
using namespace std;


int main(){
    CMatrix A, B;
    cout<< "Nhap ma tran A:";
    cin>>A;
    cout<< "\nNhap ma tran B:";
    cin>>B;
    cout<< "\nMa tran A:\n"<<A;
    cout<< "\nMa tran B:\n"<<B;

    //Test cộng 2 ma trận
    try {
        CMatrix Tong = A+B;
        cout<< "\nA + B =\n" << Tong;
    } 
    catch (const invalid_argument &e) {
        cout << e.what() << endl;
    }

    //Test trừ 2 ma trận
    try {
        CMatrix Hieu = A-B;
        cout<< "\nA - B =\n" << Hieu;
    } 
    catch (const invalid_argument &e) {
        cout << e.what() << endl;
    }

    //Test nhân ma trận với một số k
    double k;
    cout<< "\nNhap so k: ";
    cin>>k;
    cout<< "A * " << k << " =\n" << A*k;

    //Test ma trận chuyển vị
    cout<< "\nChuyen vi cua A la:\n" << A.TinhChuyenVi();

    //Test nhân ma trận với vector
    CVector v;
    cout<< "\nNhap vector v de nhan voi A (so chieu phai bang so cot cua A):\n";
    cin>>v;
    try {
        CVector Kq = A*v;
        cout<< "A * v = " << Kq;
    } 
    catch (const invalid_argument &e) {
        cout << e.what() << endl;
    }

    //Test nhân 2 ma trận
    try {
        CMatrix Kq = A*B;
        cout<< "\n\nA * B =\n" << Kq;
    } 
    catch (const invalid_argument &e) {
        cout << e.what() << endl;
    }

    return 0;
}