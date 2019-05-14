#include <iostream>

template<typename C>
void myswap(C &a, C &b)
{
    auto tmp{a};
    a = b;
    b = tmp;
}

template<> // специализация шаблонной функции
void myswap(int &a, int &b)
{
    
}

template<class C> // более legacy запись
void myswap(C *a, C *b)
{
    auto temp{*a};
    *a = *b;
    *b = temp;
}

using namespace std;

int main()
{
    int a = 10, b = 20;
    
    myswap<int>(a, b);
    cout << a << " " << b << endl;
    
    
}
