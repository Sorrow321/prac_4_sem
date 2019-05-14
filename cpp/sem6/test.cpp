#include <iostream>

using namespace std;

class A
{
protected:
    int a;
public:
    A() : a{0} {}
    void set(int t){
        a = t;
    }
    void show(){
        cout << a << endl;
    }
};

class B : A
{
private:
    double b;
public:
    void myset(int p, int q) {
        a = p;
        b = q;
    }
    void show() {
        cout << a << " " << b << endl;
    }
};

int main() {
    A x;
    x.set(15);
    x.show();
    
    B y;
    y.myset(100, 200);
    y.show();
}
