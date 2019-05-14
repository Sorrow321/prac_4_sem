#include <iostream>
#include <string>
#include <functional>
/*
*  S -> 1S0 | 1A0
*  A -> 01  | 0A1
*/

using namespace std;

int main() {
    bool flag = false;
    std::function<void(string::iterator i)> A = [&](string::iterator i) {
        if(*i == '0') { cout << 1; A(i + 1); cout << 0; } if(*i == '1') { flag = true; return; } };
    std::function<void(string::iterator i)> S = [&](string::iterator i) {
        if(flag) return; if(*i == '0') A(i); if(*i == '1') { S(i+1); cout << 0; } };
    string str;
    while (cin >> str) {
        S(str.begin());
        flag = false;
        cout << endl;
    }
    return 0;
}
