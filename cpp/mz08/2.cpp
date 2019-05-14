#include <iostream>
#include <string>

using namespace std;

int check()
{
    char a;
    int len = 0;
    string t = "";
    while(cin >> a) {
        if(a != '0' && a != '1') {
            return 0;
        }
        
        t.push_back(a);
        len++;
        
        if(a != '0') {
            break;
        }
    }
    
    while(1) {
        if(!(cin >> a)) {
            cout << 1 << endl;
            throw 10;
        }
        if(isspace(a)) {
            break;
        }
        if(a != '0' && a != '1') {
            return 0;
        }
        if(a == '1') {
            t.push_back(a);
            len++;
        }else{
            cin.putback(a);
            break;
        }
    }
    
    while(1) {
        for(int i = 0; i < len; i++) {
            if(!(cin >> a))
            {
                cout << 1 << endl;
                throw 10;
            }
            if(isspace(a)) {
                if(i == 0) {
                    return 1;
                }
                return 0;
            }
            if(a != t[i]) {
                return 0;
            }
        }
    }
}

int main()
{
    try
    {
        while(1) {
            cout << check() << endl;
        }
    }
    catch(int x){
        
    }
}
