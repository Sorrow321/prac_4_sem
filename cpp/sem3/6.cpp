struct X
{
    static int a;
    int b;
    
    static int foo()
    {
        //b++;
        a++;
        return 1;
    }
    int bar();
};

int X::A;

int main()
{
    X::a = 1;;
    
    X::foo();
    
    X x, *px = new X, &rx = x;
    //...
}

