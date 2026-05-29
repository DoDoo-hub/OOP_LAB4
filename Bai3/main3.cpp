#include <iostream>
#include "CTime.h"
using namespace std;

int main(){
    CTime t;
    cout<< "Nhap thoi diem ban dau:\n";
    cin>>t;

    cout<< "\nThoi diem ban dau: "<<t;

    int tang,giam;
    cout<< "\nNhap so giay muon cong them: ";
    cin>>tang;
    cout<< "Nhap so giay muon tru di: ";
    cin>>giam;
    //Gọi operator+/operator- với tham số là số nguyên,
    //trả về đối tượng CTime mới mà không làm thay đổi đối tượng hiện tại
    cout<< "\nt + "<<tang<<" giay = "<< t+tang; 
    cout<< "\nt - "<<giam<<" giay = "<< t-giam;

    //Test tăng 1 giây:
    //Tiền tố: ++t trả về đối tượng sau khi đã tăng 1 giây
    cout<< "\n\nTien to ++t: "<< ++t;
    //Hậu tố: t++ trả về đối tượng trước khi tăng 1 giây
    cout<< "\nHau to t++: "<< t++;
    cout<< "\nt hien tai: "<<t; //Đối tượng t đã được tăng 2 giây sau khi gọi 2 lần tăng 1 giây ở trên

    //Test giảm 1 giây:
    //Tiền tố: --t trả về đối tượng sau khi đã giảm 1 giây
    cout<< "\n\nTien to --t: "<< --t;
    //Hậu tố: t-- trả về đối tượng trước khi giảm 1 giây
    cout<< "\nHau to t--: "<< t--;
    cout<< "\nt hien tai "<<t; //Đối tượng t đã được giảm 2 giây sau khi gọi 2 lần giảm 1 giây ở trên


    return 0;
}
