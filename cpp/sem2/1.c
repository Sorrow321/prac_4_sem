#include <iostream>

void f(int a, int b)
{
    std::cout << "f(int, int)" << std::endl;
}

void f(double a, double b)
{
    std::cout << "f(double, double)" << std::endl;
}

void f(const char *a, double b)
{
    std::cout << "f(ptr, double)" << std::endl;
}

struct A
{
    A(int z)
    {
        std::cout << "A::A(int)" << std::endl;
    }
    A(long z)
    {
        std::cout << "A::A(long)" << std::endl;
    }
    
    explicit A(double z)
    {
        std::cout << "A::A(double)" << std::endl;
    }
    
    operator const char *() const
    {
        std::cout << "operator const char *" << std::endl;
        return "OK";
    }
    
    operator int() const
    {
        std::cout << "operator int" << std::endl;
        return 1;
    }
};

void f(const A &a)
{
    std::cout << "f(const A&)" << std::endl;
}

int main()
{
    f(1, 2);
    f(1.2, 2.1);
    
    // f(1, 2.0); ошибка - лучшая функция для 1 арг первая, а для 2 арг вторая
    short z;
    f(z, 5); // преобр short в int более приоритетно
    
    // f(0, 2.0); 0 может преобр в nullptr
    f(nullptr, 2);
    
    f(10);
    f(z); // может быть вызвано  стандартное преобразование перед преобр в классе
    // f(1.2); преобр double в int и в long имеет один ранг, так что будет ошибка
    f(A(1.2));
    
    A a{1.5};
    f(a, 1);
}
