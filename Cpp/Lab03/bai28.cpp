#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

class PhuongTien {
protected:
    string bienSo;
    string loai;
    double giaVe;
public:
    PhuongTien(string bs, string l, double g) 
        : bienSo(bs), loai(l), giaVe(g) {}
    virtual string getLoai() { return loai; }
    string getBienSo() { return bienSo; }
    double getGiaVe() { return giaVe; }
    virtual void hienThi() = 0;
};

class XeMay : public PhuongTien {
public:
    XeMay(string bs) : PhuongTien(bs, "Xe may", 5000) {}
    void hienThi() override {
        cout << "Xe may - Bien so: " << bienSo << endl;
    }
};

class OTo : public PhuongTien {
public:
    OTo(string bs) : PhuongTien(bs, "O to", 10000) {}
    void hienThi() override {
        cout << "O to - Bien so: " << bienSo << endl;
    }
};

class Ve {
private:
    static int soVe;
    int maVe;
    string bienSo;
    string loaiXe;
    time_t gioVao;
    time_t gioRa;
    double thanhTien;
    string tenNVThuPhi;
    bool daRa;

public:
    Ve(string bs, string lx, string tenNV) 
        : bienSo(bs), loaiXe(lx), tenNVThuPhi(tenNV), daRa(false), thanhTien(0) {
        maVe = ++soVe;
        gioVao = time(nullptr);
    }

    int tinhCap(double soGio) {
        if (soGio <= 5) return 1;
        else if (soGio <= 10) return 2;
        else if (soGio <= 24) return 3;
        else return 4;
    }

    void xuatHoaDon(double giaVe) {
        gioRa = time(nullptr);
        double soGio = difftime(gioRa, gioVao) / 3600.0;
        
        soGio = 3; 
        
        int cap = tinhCap(soGio);
        thanhTien = giaVe * cap;
        daRa = true;

        cout << "\n HOA DON \n";
        cout << "Ma ve: " << maVe << endl;
        cout << "Bien so: " << bienSo << endl;
        cout << "Loai xe: " << loaiXe << endl;
        cout << fixed << setprecision(1);
        cout << "Thoi gian gui: " << soGio << " gio" << endl;
        cout << "Cap tinh phi: " << cap << endl;
        cout << "Don gia: " << giaVe << " vnd" << endl;
        cout << "Thanh tien: " << thanhTien << " vnd" << endl;
        cout << "NV thu phi: " << tenNVThuPhi << endl;
        cout << "\n";
    }

    int getMaVe() { return maVe; }
    string getBienSo() { return bienSo; }
    string getLoaiXe() { return loaiXe; }
    double getThanhTien() { return thanhTien; }
    bool isDaRa() { return daRa; }
};
int Ve::soVe = 0;

class NguoiDung {
protected:
    string ho_ten;
    string chuc_vu;
public:
    NguoiDung(string ht, string cv) : ho_ten(ht), chuc_vu(cv) {}
    string getTen() { return ho_ten; }
    string getChucVu() { return chuc_vu; }
    virtual void hienThi() = 0;
};

class NhanVienSoatVe : public NguoiDung {
private:
    vector<Ve*> danhSachVe;
public:
    NhanVienSoatVe(string ht) : NguoiDung(ht, "NV Soat Ve") {}

    Ve* capVe(PhuongTien* xe) {
        Ve* ve = new Ve(xe->getBienSo(), xe->getLoai(), ho_ten);
        danhSachVe.push_back(ve);
        cout << "Da cap ve cho xe: " << xe->getBienSo() << endl;
        return ve;
    }

    void xacNhanRa(Ve* ve, PhuongTien* xe) {
        ve->xuatHoaDon(xe->getGiaVe());
    }

    void hienThi() override {
        cout << "NV Soat Ve: " << ho_ten << endl;
    }
};

class KhachHang : public NguoiDung {
private:
    PhuongTien* xe;
    Ve* ve;
public:
    KhachHang(string ht, PhuongTien* x) 
        : NguoiDung(ht, "Khach hang"), xe(x), ve(nullptr) {}

    void nhanVe(Ve* v) { ve = v; }
    
    void yeuCauHoaDon() {
        if (ve && !ve->isDaRa()) {
            cout << "\nKhach " << ho_ten << " yeu cau xuat hoa don." << endl;
        }
    }

    PhuongTien* getXe() { return xe; }
    Ve* getVe() { return ve; }

    void hienThi() override {
        cout << "Khach hang: " << ho_ten << " | Xe: ";
        xe->hienThi();
    }
};

class Admin : public NguoiDung {
private:
    vector<NhanVienSoatVe*> danhSachNV;
public:
    Admin(string ht) : NguoiDung(ht, "Admin") {}

    void themNV(NhanVienSoatVe* nv) {
        danhSachNV.push_back(nv);
    }

    void inDanhSachNV() {
        cout << "\nDANH SACH NHAN VIEN \n";
        for (auto nv : danhSachNV)
            nv->hienThi();
    }

    void hienThi() override {
        cout << "Admin: " << ho_ten << endl;
    }
};

int main() {
    Admin admin("Vo Van Thinh");

    // Tạo nhân viên
    NhanVienSoatVe* nv1 = new NhanVienSoatVe("Bo Kinh Van");
    NhanVienSoatVe* nv2 = new NhanVienSoatVe("Nhiep Phong");
    admin.themNV(nv1);
    admin.themNV(nv2);
    admin.inDanhSachNV();

    // Khách hàng gửi xe
    XeMay* xeMay1 = new XeMay("59B1-12345");
    OTo* oto1 = new OTo("51A-99999");

    KhachHang* kh1 = new KhachHang("Tay Mon Xuy Tuyet", xeMay1);
    KhachHang* kh2 = new KhachHang("Diep Co Thanh", oto1);

    cout << "\n CAP VE \n";
    Ve* ve1 = nv1->capVe(kh1->getXe());
    kh1->nhanVe(ve1);

    Ve* ve2 = nv2->capVe(kh2->getXe());
    kh2->nhanVe(ve2);

    cout << "\nKHACH RA \n";
    kh1->yeuCauHoaDon();
    nv1->xacNhanRa(ve1, kh1->getXe());

    kh2->yeuCauHoaDon();
    nv2->xacNhanRa(ve2, kh2->getXe());

    delete xeMay1; delete oto1;
    delete kh1; delete kh2;
    delete nv1; delete nv2;

    return 0;
}