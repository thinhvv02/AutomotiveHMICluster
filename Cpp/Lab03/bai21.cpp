#include <iostream>
using namespace std;

class XeHoi {
public:
    string tenXe;
    int namSX;
    
    void chay() {
        cout << tenXe << " dang chay!" << endl;
    }
};

int main() {
    XeHoi xe1;  
    xe1.tenXe = "Toyota";
    xe1.namSX = 2020;
    xe1.chay();

    XeHoi xe2;  
    xe2.tenXe = "Honda";
    xe2.chay();

    return 0;
}