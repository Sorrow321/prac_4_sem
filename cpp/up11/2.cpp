#include <iostream>
using namespace std;

/* 
* S -> 1A0 
* A -> 1A0 | 0B1
* B -> 0B1 | eps
*/

char c;

void get_ch()
{
    cin >> c;
}

void B()
{
    if (c == '0') {
        cout << '1';
        get_ch();
        B();
        if (c != '1') {
            throw c;
        }
        cout << '0';
        get_ch();
    }
}

void A()
{
    if (c == '1') {
        get_ch();
        A();
        if (c != '0') {
            throw c;
        }
        get_ch();
        cout << '0';
    } else if (c == '0') {
        cout << '1';
        get_ch();
        B();
        if (c != '1') {
            throw c;
        }
        cout << '0';
        get_ch();
    } else {
        throw c;
    }
}

void S()
{
    if (c != '1') {
        throw c;
    }
    get_ch();
    A();
    if (c != '0') {
        throw c;
    }
    cout << '0';
}

int main()
{
    try {
        while(1) {
            get_ch();
            S();
            cout << endl;
        }
    } catch (const char a) {
    }
}
