#ifndef CDONTHUC_H
#define CDONTHUC_H
#include <iostream>
using namespace std;

class CDonThuc
{
    private:
        int bac;
        int heso;
    public:
        CDonThuc();
        CDonThuc(int n, int a);
        ~CDonThuc();

        friend ostream& operator <<(ostream& os, const CDonThuc &dt);

        long long TinhGiaTri(int x);
        CDonThuc operator+(const CDonThuc &B)const;
        int getBac() const;
        int getHeSo() const;
        void setHeSo(int hs_moi);
};

#endif // CDONTHUC_H
