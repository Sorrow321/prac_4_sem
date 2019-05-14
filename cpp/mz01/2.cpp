#include <iostream>

class A
{
private:
    int a;
    bool flag;
public:
    A(bool p = false)
    {
        flag = p;
        std::cin >> a;
    }
    ~A()
    {
        if(flag) {
            std::cout << a << std::endl;
        }
    }
    A(const A &b) : A(true)
    {
        a += b.a;
    }
};
