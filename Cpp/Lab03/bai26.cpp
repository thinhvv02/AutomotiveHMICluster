#include <iostream>
using namespace std;

// Trừu tượng + Đóng gói
class NhanVien {
private:
    string ten;
    double luong;

public:
    NhanVien(string t, double l) : ten(t), luong(l) {}
    string getTen() { return ten; }
    double getLuong() { return luong; }
    virtual void tinhThuong() = 0; // Trừu tượng
    virtual void hienThi() {
        cout << "NV: " << ten << " | Luong: " << luong << endl;
    }
};

// Kế thừa
class NhanVienVanPhong : public NhanVien {
public:
    NhanVienVanPhong(string t, double l) : NhanVien(t, l) {}
    // Đa hình
    void tinhThuong() override {
        cout << getTen() << " thuong: " << getLuong() * 0.1 << endl;
    }
};

class NhanVienKyThuat : public NhanVien {
public:
    NhanVienKyThuat(string t, double l) : NhanVien(t, l) {}
    void tinhThuong() override {
        cout << getTen() << " thuong: " << getLuong() * 0.2 << endl;
    }
};

int main() {
    NhanVien* nv1 = new NhanVienVanPhong("An", 10000000);
    NhanVien* nv2 = new NhanVienKyThuat("Binh", 15000000);

    nv1->hienThi(); nv1->tinhThuong();
    nv2->hienThi(); nv2->tinhThuong();

    delete nv1; delete nv2;
    return 0;
}