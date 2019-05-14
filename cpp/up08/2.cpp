#include <iostream>
#include <string>

using namespace std;


int check2(const string &a, size_t i, size_t ones, size_t zeros)
{
    size_t z_ = 0;
    size_t o_ = 0;
    for(; i < a.length(); i++) {
        if(a[i] == '0') {
            z_++;
        }else if(a[i] == '1') {
            o_++;
            break;
        }else{
            return 0;
        }
    }
    if(!z_ || !o_) {
        return 0;
    }
    for(; i < a.length(); i++) {
        if(a[i] == '1') {
            o_++;
        }else if(a[i] == '0') {
            if(o_ != ones || z_ != zeros) {
                return 0;
            }
            return check2(a, i, ones, zeros);
        }else{
            return 0;
        }
    }
    if(o_ == ones && z_ == zeros) {
        return 1;
    }
    return 0;
}

int check(const string &a)
{
    size_t ones = 0;
    size_t zeros = 0;
    size_t i = 0;
    for(; i < a.length(); i++) {
        if(a[i] == '0') {
            zeros++;
        }else if(a[i] == '1') {
            ones++;
            break;
        }else{
            return 0;
        }
    }
    if(!zeros || !ones) {
        return 0;
    }
    
    for(; i < a.length(); i++) {
        if(a[i] == '1') {
            ones++;
        }else if(a[i] == '0') {
            return check2(a, i, ones, zeros);
        }else{
            return 0;
        }
    }
    return 1;
}

int main()
{
    string a;
    while(cin >> a)
    {
        cout << check(a) << endl;
    }
}
