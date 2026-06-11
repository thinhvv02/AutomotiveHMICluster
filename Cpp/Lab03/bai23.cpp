#include <iostream>
using namespace std;

class DongVat {
public:
    string ten;
    void an() { cout << ten << " dang an" << endl; }
};

class Cho : public DongVat {
public:
    void sua() { cout << ten << " go go!" << endl; }
};

class Meo : public DongVat {
public:
    void kedeu() { cout << ten << " meo meo!" << endl; }
};

int main() {
    Cho c; c.ten = "Buddy"; c.an(); c.sua();
    Meo m; m.ten = "Kitty"; m.an(); m.kedeu();
    return 0;
}