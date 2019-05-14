#include <iostream>
#include <string>

using namespace std;

/* язык типа 0

S = aXPQ
P = YXP | ε
Q = UVQ | ε
aY = aa
aU = a0
0U = 00
0X = 0b
bX = bb
bV = b1
1V = 11
XY = YX
UY = YU
VY = YV
XU = UX
VU = UV
VX = XV
*/
int is_good(string &a)
{
    size_t m = 0;
    size_t n = 0;
    size_t i = 0;
    for(; ; i++) {
        if(a[i] == 'a') {
            m++;
        }else if(a[i] == '0') {
            break;
        }else{
            return 0;
        }
    }
    for(; ; i++) {
        if(a[i] == '0') {
            n++;
        }else if(a[i] == 'b') {
            break;
        }else{
            return 0;
        }
    }
    size_t j = i;
    for(size_t t = 0; t < m; t++) {
        if(a[j++] != 'b') {
            return 0;
        }
    }
    for(size_t t = 0; t < n; t++) {
        if(a[j++] != '1') {
            return 0;
        }
    }
    if(!m || !n || a.length() != (2 * (m + n))) {
        return 0;
    }
    return 1;
}

int main()
{
    string a;
    while(cin >> a) {
        cout << is_good(a) << endl;
    }
}
