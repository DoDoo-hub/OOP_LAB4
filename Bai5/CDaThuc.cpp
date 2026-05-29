#include <iostream>
#include <vector>
#include "CDaThuc.h"
using namespace std;


CDaThuc::CDaThuc():N(0){}

CDaThuc::CDaThuc(int bac):N(bac){}

//vector<CDonThuc> P tự động gọi hàm hủy của nó
//để giải phóng bộ nhớ cho các đơn thức
CDaThuc::~CDaThuc(){}

istream& operator >>(istream& is, CDaThuc &dt){
    cout<<"Nhap bac cua da thuc: ";
    is>>dt.N;
    for (int i=dt.N;i>-1;i--){ //thêm các đơn thức bậc N->0 vào P
        int a;
        cout<<"Nhap he so cua x^"<<i<<": ";
        is>>a;
        dt.P.push_back(CDonThuc(i,a));
    }
    return is;
}

ostream& operator <<(ostream& os, const CDaThuc &dt){
    bool laDonThucDau=true;

    for(int i=0;i<=dt.N;i++){
        int hs= dt.P[i].getHeSo();
        if(hs==0) continue; //Bỏ qua nếu hệ số bằng 0

        if(laDonThucDau){
            if(hs<0) os<< "-";
        }
        else{
            if(hs>0) os<< " + ";
            else os<< " - ";
        }

        os<< dt.P[i]; // In đơn thức(đã lấy trị tuyệt đối hệ số)

        laDonThucDau=false;
    }

    if(laDonThucDau) os<< "0"; // Nếu đa thức = 0 -> In ra: 0
    return os;
}

long long CDaThuc::operator()(int x){
    long long kq=0;

    //cộng các giá trị(khi biết x) của từng đơn thức
    for (int i=0;i<=N;i++){
        kq+= P[i].TinhGiaTri(x);
    }
    return kq;
}

CDaThuc CDaThuc::operator+(const CDaThuc &B){ //Trả về đa thức C=A+B
    int Na=this->N;
    int Nb=B.N;
    CDaThuc C;//Đa thức chứa kết quả phép tổng
    int khoangcach=max(Na,Nb)-min(Na,Nb);//Tính chênh lệch bậc của A và B

    if(khoangcach>0){ //Trường hợp 2 đa thức có bậc khác nhau

        //Mục tiêu: Đưa các đơn thức bậc cao của đa thức lớn hơn vào trước,
        //sau đó mới cộng các đơn thức có cùng bậc với nhau.

        if(Na>Nb){
            for(int i=0;i<khoangcach;i++){
                CDonThuc c=this->P[i];
                C.P.push_back(c);
            }

            for(int i=0;i<=Nb;i++){
                CDonThuc c= this->P[i+khoangcach] + B.P[i];
                C.P.push_back(c);
            }
        }

        else{ //Nb>Na
            for(int i=0;i<khoangcach;i++){
                CDonThuc c=B.P[i];
                C.P.push_back(c);
            }

            for(int i=0;i<=Na;i++){
                CDonThuc c= B.P[i+khoangcach] + this->P[i];
                C.P.push_back(c);
            }
        }
    }


    else{ //Trường hợp 2 đa thức có cùng bậc
        bool check=0;// đã gặp đơn thức c đầu tiên !=0?
        for(int i=0;i<=Na;i++){
            CDonThuc c= this->P[i] + B.P[i];
            if(c.getHeSo()!=0){
                check=1;
                C.P.push_back(c);
            }
            else //c.getHeSo()==0
                if(check==1) C.P.push_back(c);
                // check=0 thì đến giờ các đơn thức đều=0, không cần thêm vào C
        }
    }

    C.N= C.P.size()-1;
    if(C.N==-1) C.P.push_back(CDonThuc(0,0)); // nếu A=B -> C=0
    return C;
}

CDaThuc CDaThuc::operator-(const CDaThuc &B){ //Trả về đa thức C= A - B = A + -B
    //chuyển B thành -B (Đảo ngược dấu các đơn thức của B)
    CDaThuc B_copy=B;
    for(int i=0;i<=B_copy.N;i++){
        B_copy.P[i].setHeSo(-1 * B_copy.P[i].getHeSo());
    }

    return this->operator+(B_copy); //trả về phép hiệu: A - B = phép tổng: A + -B
}

CDaThuc CDaThuc::operator*(const CDaThuc &B){ //Trả về đa thức C=A*B
    int bacC= this->N + B.N; // Bậc của đa thức C bằng tổng bậc của A và B
    CDaThuc C(bacC);
    for(int i=bacC;i>=0;i--){
        C.P.push_back(CDonThuc(i,0));
    }

    // Nhân từng đơn thức của A với từng đơn thức của B rồi cộng dồn kết quả vào vị trí bậc tương ứng trong C
    for(int i=0;i<=this->N;i++){
        for(int j=0;j<=B.N;j++){ 
            int hesoMoi= C.P[i+j].getHeSo() + this->P[i].getHeSo() * B.P[j].getHeSo();
             C.P[i+j].setHeSo(hesoMoi);
        }
    }
    return C;    
}