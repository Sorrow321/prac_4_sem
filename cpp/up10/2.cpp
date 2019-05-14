#include <iostream>
using namespace std;

/*
 * S aAd
 * A aAd | bBc
 * B bBc | eps
*/

void B(int b)
{
    if(b > 0) {
        cout << 'b';
        B(b-1);
        cout << 'c';
    }
}

void A(int a, int t)
{
    if(a > 0) {
        cout << 'a';
        A(a - 1, t);
        cout << 'd';
    }else{
        B(t);
    }
}

void S(int a, int n)
{
    if(a > 0) {
        cout << 'a';
        A(a - 1, n / 2 - a);
        cout << 'd';
        cout << endl;
        S(a - 1, n);
    }
}
    

int main()
{
    int n;
    cin >> n;
    if(!(n % 2) && n >= (1 << 2)) {
        S(n / 2 - 1, n);
    }
}
