#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <new>
#include <utility>

namespace numbers
{
    class complex {
    private:
        double a, b;
    public:
        complex(double c = 0, double d = 0) : a{ c }, b{ d }
        {
        }

        explicit complex(const char *str)
        {
            sscanf(str, "(%lf,%lf)", &a, &b);
        }

        double get_re() const
        {
            return a;
        }

        double get_im() const
        {
            return b;
        }

        double abs2() const
        {
            return a * a + b * b;
        }

        double abs() const
        {
            return sqrt(abs2());
        }

        void to_string(char *buf, size_t ssize) const
        {
            snprintf(buf, ssize, "(%.10g,%.10g)", a, b);
        }

        friend complex operator-(const complex& x);
        friend complex operator~(const complex& x);
        friend complex operator *(const complex& y, const complex& x);
        friend complex operator /(const complex& y, const complex& x);
        friend complex operator +(const complex& y, const complex& x);
        friend complex operator -(const complex& y, const complex& x);
    };

    complex operator-(const complex& x)
    {
        return complex(x.a * -1.0, x.b * -1.0);
    }

    complex operator~(const complex& x)
    {
        return complex(x.a, x.b * -1.0);
    }

    complex operator  /(const complex& y, const complex& x)
    {
        double r1, r2;
        r1 = (y.a * x.a + y.b * x.b) / (x.a * x.a + x.b * x.b);
        r2 = (y.b * x.a - y.a * x.b) / (x.a * x.a + x.b * x.b);
        return complex(r1, r2);
    }
    complex operator*(const complex& y, const complex& x)
    {
        double r1, r2;
        r1 = y.a * x.a - y.b * x.b;
        r2 = y.a * x.b + y.b * x.a;
        return complex(r1, r2);
    }
    complex operator+(const complex& y, const complex& x)
    {
        return complex(y.a + x.a, y.b + x.b);
    }
    complex operator-(const complex& y, const complex& x)
    {
        return complex(y.a - x.a, y.b - x.b);
    }

    class complex_stack
    {
        static constexpr size_t default_capacity = 8;
        size_t ssize = 0;
        size_t capacity = default_capacity;
        complex* stack = nullptr;
    public:
        void clear()
        {
            for (size_t i = 0; i < ssize; i++) {
                stack[i].~complex();
            }
            ::operator delete[](stack);
        }
        void make_move(complex_stack& x)
        {
            clear();
            ssize = 0;
            capacity = default_capacity;
            stack = static_cast<complex*>(::operator new[](capacity * sizeof(complex)));

            std::swap(ssize, x.ssize);
            std::swap(capacity, x.capacity);
            std::swap(stack, x.stack);
        }
        complex_stack(size_t size_ = 0, size_t capacity_ = default_capacity) : ssize{ size_ }, capacity{ capacity_ }
        {
            stack = static_cast<complex*>(::operator new[](capacity * sizeof(complex)));
        }
        complex_stack(const complex_stack& x) : ssize{ x.ssize }, capacity{ x.capacity }
        {
            stack = static_cast<complex*>(::operator new[](capacity * sizeof(complex)));
            for (size_t i = 0; i < ssize; i++) {
                new (stack + i) complex(x.stack[i]);
            }
        }
        complex_stack(complex_stack&& x)
        {
            make_move(x);
        }
        ~complex_stack()
        {
            clear();
        }
        complex_stack& operator=(const complex_stack& x)
        {
            if (this != &x)
            {
                clear();
                ssize = x.ssize;
                capacity = x.capacity;
                stack = static_cast<complex*>(::operator new[](capacity * sizeof(complex)));
                for (size_t i = 0; i < ssize; i++) {
                    new (stack + i) complex(x[i]);
                }
            }
            return *this;
        }
        complex_stack& operator =(complex_stack&& x)
        {
            if (this != &x) {
                make_move(x);
            }
            return *this;
        }
        complex_stack operator<<(const complex& x) const
        {
            complex_stack temp(ssize + 1, capacity);
            if (temp.capacity < temp.ssize) {
                temp.capacity *= 2;
            }
            temp.clear();
            temp.stack = static_cast<complex*>(::operator new[](temp.capacity * sizeof(complex)));
            for (size_t i = 0; i < ssize; i++) {
                new (temp.stack + i) complex(stack[i]);
            }
            new (temp.stack + ssize) complex(x);
            return std::move(temp);
        }
        complex_stack operator~() const
        {
            complex_stack temp(*this);
            temp.stack[--temp.ssize].~complex();
            return std::move(temp);
        }
        complex& operator [](size_t i) const
        {
            return stack[i];
        }
        complex& operator+() const
        {
            return stack[ssize - 1];
        }
        size_t size() const
        {
            return ssize;
        }
    };

    complex eval(char **args, const complex &z)
    {
        complex_stack stack;
        for (unsigned i = 0; args[i] != nullptr; i++)
        {
            switch (args[i][0])
            {
            case '(': {
                complex x = complex(args[i]);
                stack = stack << x;
                break;
            }
            case 'z': {
                stack = stack << z;
                break;
            }
            case '+': {
                size_t s = stack.size() - 1;
                complex x = stack[s];
                complex y = stack[s - 1];
                x = x + y;
                stack[s - 1] = x;
                stack = ~stack;
                break;
            }
            case '-': {
                size_t s = stack.size() - 1;
                complex x = stack[s];
                complex y = stack[s - 1];
                x = y - x;
                stack[s - 1] = x;
                stack = ~stack;
                break;
            }
            case '*': {
                size_t s = stack.size() - 1;
                complex x = stack[s];
                complex y = stack[s - 1];
                x = x * y;
                stack[s - 1] = x;
                stack = ~stack;
                break;
            }
            case '/': {
                size_t s = stack.size() - 1;
                complex x = stack[s];
                complex y = stack[s - 1];
                x = y / x;
                stack[s - 1] = x;
                stack = ~stack;
                break;
            }
            case '!': {
                complex t = +stack;
                stack = stack << t;
                break;
            }
            case ';': {
                stack = ~stack;
                break;
            }
            case '~': {
                size_t s = stack.size() - 1;
                stack[s] = ~(stack[s]);
                break;
            }
            case '#': {
                size_t s = stack.size() - 1;
                stack[s] = -(stack[s]);
                break;
            }
            default:
                break;
            }
        }
        return +stack;
    }
};


int main(int argc, char *argv[])
{
    numbers::complex c(argv[1]);
    double r;
    int n;
    sscanf(argv[2], "%lf", &r);
    sscanf(argv[3], "%d", &n);
    char **func = argv + 4;
    double dphi = 2 * M_PI / n;

    numbers::complex sum(0.0, 0.0);
    for (int i = 0; i < n; i++) {
        double arg = 2 * M_PI * i / n;
        numbers::complex z = numbers::complex(r * cos(arg), r * sin(arg));

        sum = sum + z * numbers::eval(func, c + z);
    }
    sum = sum * numbers::complex(0, 1) * dphi;

    std::cout << std::setprecision(10) << "(" << sum.get_re() << "," << sum.get_im() << ")" << std::endl;
    return 0;
}