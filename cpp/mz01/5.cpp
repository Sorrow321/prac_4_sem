#include <iostream>
#include <stdio.h>
#include <iomanip> 
#include <string>

class Rational
{
private:
    int a, b;
public:
    Rational(int p, int q = 1) : a{p}, b{q}
    {
        normalize();
    }
    Rational() : a{0}, b{1}
    {
    }
    Rational& operator =(const Rational& p)
    {
        this->a = p.a;
        this->b = p.b;
        return *this;
    }
    void normalize()
    {
        int c = gcd(a, b);
        a /= c;
        b /= c;
        if (b < 0) {
            b *= -1;
            a *= -1;
        }
    }
    
    int gcd(int m, int n)
    {
        if (!n) {
            return m;
        }else{
            return gcd(n, m % n);
        }
    }

    long long gcd(long long m, long long n)
    {
        if (!n) {
            return m;
        }else{
            return gcd(n, m % n);
        }
    }
    
    
    Rational& Add(const Rational& q)
    {
        long long lo = a * q.b + b * q.a;
        long long lu = b * q.b;
        long long gc = gcd(lo, lu);
        lo /= gc;
        lu /= gc;
        
        a = lo;
        b = lu;
        normalize();
        return *this;
    }
    
    Rational& Substract(const Rational& q)
    {
        return Add(Rational(-q.a, q.b));
    }
    
    Rational& Multiply(const Rational& q)
    {
        long long lo = a * q.a;
        long long lu = b * q.b;
        long long gc = gcd(lo, lu);
        lo /= gc;
        lu /= gc;
        
        a = lo;
        b = lu;
        normalize();
        return *this;
    }
    
    Rational& Divide(const Rational& q)
    {
        if(q.a > 0) {
            return Multiply(Rational(q.b, q.a));
        }else{
            return Multiply(Rational(-q.b, -q.a));
        }
    }
    
    bool IsInteger() const
    {
        return (b == 1)? true : false;
    }
    
    bool EqualTo(const Rational& q) const
    {
        return (a * q.b == b * q.a)? true : false;
    }
    
    int CompareTo(const Rational& q)
    {
        return a * q.b - b * q.a;
    }
    
    std::string ToString() const
    {
        return std::to_string(a) + ":" + std::to_string(b);
    }
};
