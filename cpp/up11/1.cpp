#include <iostream>
using namespace std;

/*
 * S -> AB
 * A -> 3A3 | 4A4| eps
 * B -> 1B1 | 2B2 | eps
*/
 

void A(int n, int last, bool start = false)
{
    if(!n) {
        return;
    }
    cout << 3;
    A(n - 1, 3);
    cout << 3;
}

int main()
{
    A(3, 0, true);
}
