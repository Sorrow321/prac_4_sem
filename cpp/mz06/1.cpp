#include <iostream>
#include <string>

using namespace std;

class A
{
public:
    string *kek;
    A() {}
    A(string *x) : kek{x} {}
    ~A(){
        cout << *kek << endl;
    }
};

void foo()
{
    string a;
    if(cin >> a) {
        A p(&a);
        try {
            foo();
        } catch(int x) {
            throw 10;
        }
    }else{
        throw 10;
    }
}

int main()
{
    try {
        foo();
    } catch(int x) {}
}
