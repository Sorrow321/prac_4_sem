int f(int x, int y = 1, int z = 2);

int f(double x);



// в скомпилированной программе все уже подставлено

int main()
{
    f(10);
    f(10, 11);
    f(10, 11, 12);
}
