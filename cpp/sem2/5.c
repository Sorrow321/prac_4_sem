#include <iostream>

using namespace std;

struct B
{
    int b;
    
    B(int b) : b(b) {}
};

struct A
{
private:
    int a;
    
public:
    A(int a) : a(a) {}
    A(const B&b) : a(10) {}
    
    int operator + () const // унарный плюс
    {
        cout << "A::operator +()" << endl;
        return a;
    }
    
    Rational& operator + (const A &a) const
    {
        cout << "A::operator +(const A &a)" << endl;
        return 0;
    }
    
    int operator -() const;
};

int A::operator -() const
{
    cout << "A::operator -" << endl;
    return -a;
}

int operator !(const A &a)
{
    return 1;
}

int main()
{
    A a(1);
    +a;
    -a;
    
    B b(2);
    +b;
}
