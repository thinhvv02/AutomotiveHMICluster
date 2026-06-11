#include <iostream>
using namespace std;

class SinhVien {
private:
    string ten;
    float diemTB;

public:
    void setTen(string t) { ten = t; }
    void setDiem(float d) {
        if (d >= 0 && d <= 10) diemTB = d;
        else cout << "Diem khong hop le!" << endl;
    }
    string getTen() { return ten; }
    float getDiem() { return diemTB; }

    void hienThi() {
        cout << "Ten: " << ten << " | Diem TB: " << diemTB << endl;
    }
};

int main() {
    SinhVien sv;
    sv.setTen("Thinh");
    sv.setDiem(8.5);
    sv.hienThi();
    return 0;
}