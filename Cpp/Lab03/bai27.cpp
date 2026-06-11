#include <iostream>
using namespace std;

class Base {
public:
    int pub = 1;      
protected:
    int prot = 2;     
private:
    int priv = 3;   
};

class DerivedClass : public Base {
public:
    void show() {
        cout << "public: " << pub << endl;    
        cout << "protected: " << prot << endl;            
    }
};

int main() {
    Base b;
    cout << b.pub << endl;  

    DerivedClass d;
    d.show();
    return 0;
}