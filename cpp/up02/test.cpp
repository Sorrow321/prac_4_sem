#include <iostream>

using namespace std;

class A
{
public:
    A(){}
    A(const A &b)
    {
        cout << "copied!" << endl;
    }
};

int main()
{
    A x;
    A y(&x);
    return 0;
}
