#include <iostream>
using namespace std;

class TaiKhoanNganHang {
private:
    double soDu;        
    string maTaiKhoan;

public:
    TaiKhoanNganHang(string ma, double du) {
        maTaiKhoan = ma;
        soDu = du;
    }

    void napTien(double soTien) {
        soDu += soTien;
        cout << "Nap " << soTien << ". So du: " << soDu << endl;
    }

    void rutTien(double soTien) {
        if (soTien <= soDu)
            soDu -= soTien;
        else
            cout << "So du khong du!" << endl;
    }

    double xemSoDu() { return soDu; }
};

int main() {
    TaiKhoanNganHang tk("TK001", 1000000);
    tk.napTien(500000);
    tk.rutTien(200000);
    cout << "So du hien tai: " << tk.xemSoDu() << endl;
    return 0;
}