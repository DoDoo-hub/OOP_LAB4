#include <iostream>
#include "CDate.h"
using namespace std;

//Hàm main của class CDate
int main(){
    CDate d1;
    cout << "Nhap ngay thu nhat:\n";
    cin>>d1;

    cout << "\nNgay ban dau d1: "<<d1;

    int them, bot;
    cout<< "\nNhap so ngay muon cong them: ";
    cin>>them;
    cout<< "Nhap so ngay muon tru di: ";
    cin>>bot;

    //Gọi operator+/operator- với tham số là số nguyên,
    //trả về đối tượng CDate mới mà không làm thay đổi đối tượng hiện tại
    cout<< "\nd1 + "<<them<<" ngay = "<< d1+them;
    cout<< "\nd1 - "<<bot<<" ngay = "<< d1-bot;

    // Test khoảng cách giữa 2 ngày
    CDate d2;
    cout<< "\n\nNhap ngay thu hai:\n";
    cin>>d2;
    cout<< "Ngay thu hai d2: "<<d2;
    cout<< "\n\nKhoang cach giua "<<d1<<" va "<<d2<<" la: "<<d1-d2<<" ngay";

    // Test tăng 1 ngày
    // Tiền tố: ++date trả về đối tượng sau khi đã tăng 1 ngày
    cout<< "\n\nTien to ++d1: "<< ++d1;
    // Hậu tố: date++ trả về đối tượng trước khi tăng 1 ngày
    cout<< "\nHau to d1++: "<< d1++;
    cout<< "\nd1 hien tai: "<<d1; //Đối tượng d1 đã được tăng 2 ngày sau khi gọi 2 lần tăng 1 ngày ở trên

    // Test giảm 1 ngày
    // Tiền tố: --date trả về đối tượng sau khi đã giảm 1 ngày
    cout<< "\n\nTien to --d1: "<< --d1;
    // Hậu tố: date-- trả về đối tượng trước khi giảm 1 ngày
    cout<< "\nHau to d1--: "<< d1--;
    cout<< "\nd1 hien tai: "<<d1; //Đối tượng d1 đã được giảm 2 ngày sau khi gọi 2 lần giảm 1 ngày ở trên

    return 0;
}
