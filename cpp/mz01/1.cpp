class Sum
{
    int a, b;
public:
    Sum(int c, int d): a{c}, b{d}   
    {
    }
    Sum(const Sum &p, int q): a{p.a + p.b}, b{q}
    {
    }
    int get() const
    {
        return a + b;
    }
};
