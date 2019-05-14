#include <iostream>

struct A
{
    explicit operator bool() const
    {
        std::cout << "operator bool" << std::endl;
        return false;
    }
    
    /*
    operator void *() const
    {
        std::cout << "operator void *" << std::endl;
    }*/
};

int main()
{
    A a;
    
    
    
    while(a) {
    }
}
