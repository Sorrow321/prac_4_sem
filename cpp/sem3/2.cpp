class Proxy
{
    struct Holder
    {
        int value;
    }
    
    Holder *data{};
    
public:
    const Holder *operator -> () const
    {
        return data;
    }
};

struct Func
{
    int operator() (int a) const
    {
        return a + 1;
    }
    double operator()(int a, int b) const
    {
        return (a + b + 0.0) / 2;
    }
}

#include <iostream>

int main()
{
    Proxy p{};
    
    std::cout << p->value << std::endl;
}
