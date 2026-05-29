#ifndef CDATHUC_H
#define CDATHUC_H
#include <vector>
#include "CDonThuc.h"

class CDaThuc
{
    private:
        int N;
        std::vector<CDonThuc> P;
    public:
        CDaThuc();
        CDaThuc(int bac);
        ~CDaThuc();

        // Nạp chồng toán tử nhập/xuất (friend)
        friend istream& operator >>(istream& is, CDaThuc &dt);
        friend ostream& operator <<(ostream& os, const CDaThuc &dt);

        long long operator()(int x);//Tính giá trị của đa thức tại x (gọi như hàm)
        CDaThuc operator+(const CDaThuc &B);
        CDaThuc operator-(const CDaThuc &B);
        CDaThuc operator*(const CDaThuc &B);
};

#endif // CDATHUC_H
