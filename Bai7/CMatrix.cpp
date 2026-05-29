#include "CMatrix.h"
#include <stdexcept>

CMatrix::CMatrix(int dong, int cot): iDong(dong), iCot(cot), data(dong, vector<double>(cot, 0.0)){}

CMatrix::~CMatrix(){}

istream& operator>>(istream& is, CMatrix &M){
    cout<< "\nNhap so dong cua ma tran: ";
    is>>M.iDong;
    cout<< "Nhap so cot cua ma tran: ";
    is>>M.iCot;
    M.data.resize(M.iDong); //Thay đổi kích thước của vector 1 chiều để chứa iDong dòng
    for(int i=0;i<M.iDong;i++){
        M.data[i].resize(M.iCot); //Thay đổi kích thước của vector 2 chiều để chứa iCot cột
        for(int j=0;j<M.iCot;j++){
            cout<< "Nhap phan tu ["<<i+1<<"]["<<j+1<<"]: ";
            is>>M.data[i][j];
        }
    }
    return is;
}

ostream& operator<<(ostream& os, const CMatrix &M){
    for(int i=0;i<M.iDong;i++){
        for(int j=0;j<M.iCot;j++){
            os<<M.data[i][j]<<"\t";
        }
        os<<"\n";
    }
    return os;
}

int CMatrix::getDong() const { return this->iDong; }

int CMatrix::getCot() const { return this->iCot; }

CMatrix CMatrix::operator+(const CMatrix &B) const { //Trả về ma trận tổng: C= A+B
    if (this->iDong != B.iDong || this->iCot != B.iCot) {
        throw invalid_argument("\nLoi: Hai ma tran khong cung kich thuoc de cong!");
    }
    CMatrix kq(this->iDong, this->iCot);
    for (int i=0; i < this->iDong; i++) {
        for (int j=0; j < this->iCot; j++) {
            kq.data[i][j] = this->data[i][j] + B.data[i][j];
        }
    }
    return kq;
}

CMatrix CMatrix::operator-(const CMatrix &B) const {  //Trả về ma trận hiệu: C= A-B
    if (this->iDong != B.iDong || this->iCot != B.iCot) {
        throw invalid_argument("\nLoi: Hai ma tran khong cung kich thuoc de tru!");
    }
    CMatrix kq(this->iDong, this->iCot);
    for (int i=0; i < this->iDong; i++) {
        for (int j=0; j < this->iCot; j++) {
            kq.data[i][j] = this->data[i][j] - B.data[i][j];
        }
    }
    return kq;
}

CMatrix CMatrix::operator*(double k) const {    // C= A*k
    CMatrix kq(this->iDong, this->iCot);
    for (int i=0; i < this->iDong; i++) {
        for (int j=0; j < this->iCot; j++) {
            kq.data[i][j] = this->data[i][j] * k;
        }
    }
    return kq;
}

CMatrix operator*(double k, const CMatrix &M) { // C= k*A
    return M * k;
}

CMatrix CMatrix::TinhChuyenVi() const {  // Trả về ma trận chuyển vị của ma trận hiện tại
    CMatrix kq(this->iCot, this->iDong); 
    for (int i=0; i < this->iDong; i++) {
        for (int j=0; j < this->iCot; j++) {
            kq.data[j][i] = this->data[i][j]; //Đổi chỗ i và j để tạo chuyển vị
        }
    }
    return kq;
}

CVector CMatrix::operator*(const CVector &V) const{
    if (this->iCot != V.getSoChieu()) {
        throw invalid_argument("\nLoi: So cot cua ma tran khong bang so chieu cua vector de nhan!");
    }
    CVector kq(this->iDong);
    for (int i=0; i < this->iDong; i++) {
        double sum = 0.0;
        for (int j=0; j < this->iCot; j++) {
            sum += this->data[i][j] * V.getToaDo(j);
        }
        kq.setToaDo(i, sum);
    }
    return kq;
}

CMatrix CMatrix::operator*(const CMatrix &other) const {
    if (this->iCot != other.iDong) {
        throw invalid_argument("\nLoi: So cot cua ma tran A khong bang so dong cua ma tran B de nhan!");
    }
    CMatrix kq(this->iDong, other.iCot);
    for (int i=0; i < this->iDong; i++) {
        for (int j=0; j < other.iCot; j++) {
            double sum = 0.0;
            for (int k=0; k < this->iCot; k++) {
                sum += this->data[i][k] * other.data[k][j];
            }
            kq.data[i][j] = sum;
        }
    }
    return kq;
}

/*double CMatrix::TinhDinhThuc() {
    if (this->iDong != this->iCot) {
        throw invalid_argument("\nLoi: Chi ma tran vuong moi co dinh thuc!");
    }
    int n = this->iDong;
    vector<vector<double>> temp = this->data; //Sao chép dữ liệu để tính định thức
    double det = 1.0;

    for (int i=0; i < n; i++) {
        // Tìm phần tử lớn nhất trong cột i để làm pivot
        int pivot = i;
        for (int j=i+1; j < n; j++) {
            if (abs(temp[j][i]) > abs(temp[pivot][i])) {
                pivot = j;
            }
        }
        if (abs(temp[pivot][i]) < 1e-10) { //Nếu phần tử pivot gần bằng 0 thì định thức bằng 0
            return 0.0;
        }
        if (pivot != i) { //Đổi chỗ dòng nếu cần thiết
            swap(temp[i], temp[pivot]);
            det = -det; //Đổi dấu định thức khi đổi dòng
        }
        det *= temp[i][i]; //Nhân với phần tử trên đường chéo chính
        for (int j=i+1; j < n; j++) { //Loại bỏ các phần tử dưới pivot
            double factor = temp[j][i] / temp[i][i];
            for (int k=i; k < n; k++) {
                temp[j][k] -= factor * temp[i][k];
            }
        }
    }
    return det;
}
*/