#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

void show_lh(int n, int k, int lower, int higher, string &str)
{
    unsigned long long t = pow(2, k);
    for(unsigned counter = 0; counter < t; counter++) {
        unsigned l = counter;
        
        //cout << "STARTUEM: " << endl;
        
        string mystr = "";
        for(int i = 0; i < k; i++) {
            unsigned mybit = (l >> (k - 1)) & 1u;
            if(mybit == 1) {
                if(lower == 3)
                    cout << higher;
                mystr += '0' + higher;
            }else{
                if(lower == 3)
                    cout << lower;
                mystr += '0' + lower;
            }
            l = l << 1;
        }
        
        if(!str.empty()) {
            cout << str;
        }
        
        if(lower == 1) {
            //cout << "ENDUEM: " << endl;
            show_lh(n, n - k, 3, 4, mystr);
        }else{
            cout << endl;
        }
    }
}

int main()
{
    int k;
    cin >> k;
    string t = "";
    for(int i = 0; i <= k; i++) {
        show_lh(k, i, 1, 2, t);
    }
    
    return 0;
}
