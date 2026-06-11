#include <iostream>
using namespace std;

class HinhHoc {
public:
    virtual double tinhDienTich() = 0; 
    virtual void moTa() { cout << "Hinh hoc" << endl; }
};

class HinhTron : public HinhHoc {
    double banKinh;
public:
    HinhTron(double r) : banKinh(r) {}
    double tinhDienTich() override {
        return 3.14 * banKinh * banKinh;
    }
    void moTa() override { cout << "Hinh tron" << endl; }
};

class HinhChuNhat : public HinhHoc {
    double dai, rong;
public:
    HinhChuNhat(double d, double r) : dai(d), rong(r) {}
    double tinhDienTich() override { return dai * rong; }
    void moTa() override { cout << "Hinh chu nhat" << endl; }
};

int main() {
    HinhHoc* h1 = new HinhTron(5);
    HinhHoc* h2 = new HinhChuNhat(4, 6);

    h1->moTa(); cout << "Dien tich: " << h1->tinhDienTich() << endl;
    h2->moTa(); cout << "Dien tich: " << h2->tinhDienTich() << endl;

    delete h1; delete h2;
    return 0;
}