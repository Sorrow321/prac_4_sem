#include <iostream>
#include <string>

using namespace std;

int check(string &a)
{
    int len = a.length();
    int state = 0;
    if(a[0] == '3' || a[0] == '4') {
        int p;
        for(p = 1; p < len; p++) {
            if(a[p] == '3' || a[p] == '4') {
                continue;
            }else if(a[p] == '1' || a[p] == '2') {
                state = 1;
                break;
            }else{
                return 0;
            }
        }
        p++;
        if(state == 1) {
            for(; p < len; p++) {
                if(a[p] == '1' || a[p] == '2') {
                    continue;
                }else{
                    return 0;
                }
            }
            return 1;
        }else{
            return 1;
        }
    }else if(a[0] == '1' || a[0] == '2') {
        int p;
        for(p = 1; p < len; p++) {
            if(a[p] == '1' || a[p] == '2') {
                continue;
            }else{
                return 0;
            }
        }
        return 1;
    }else{
        return 0;
    }
}

int main()
{
    string a;
    
    while(cin >> a) {
        cout << check(a) << endl;
    }
}
