#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

namespace numbers
{
    class complex{
    private:
        double a, b;
    public:
        complex(double c = 0, double d = 0) : a {c}, b {d}
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
            return a*a + b*b;
        }
        
        double abs() const
        {
            return sqrt(abs2());
        }
        
        void to_string(char *buf, size_t size) const
        {
            snprintf(buf, size, "(%.10g,%.10g)", a, b);
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
}
