#include <cmath>
#include <string>
#include <sstream>
#include <iostream>

class Rectangle : public Figure
{
private:
    double a = 0, b = 0;
public:
    virtual double get_square() const override
    {
        return a * b;
    }
    
    static Rectangle* make(const std::string &a)
    {
        std::stringstream geek(a);
        double p, q;
        geek >> p >> q;
        Rectangle * rec = new Rectangle;
        rec->a = p;
        rec->b = q;
        return rec;
    }
};

class Square : public Figure
{
private:
    double a = 0;
public:
    virtual double get_square() const override
    {
        return a * a;
    }
    
    static Square* make(const std::string &a)
    {
        std::stringstream geek(a);
        double p;
        geek >> p;
        Square * sq = new Square;
        sq->a = p;
        return sq;
    }
};

class Circle : public Figure
{
private:
    double r = 0;
public:
    virtual double get_square() const override
    {
        return M_PI * r * r;
    }
    
    static Circle* make(const std::string &a)
    {
        std::stringstream geek(a);
        double p;
        geek >> p;
        
        Circle * cir = new Circle;
        cir->r = p;
        return cir;
    }
};
