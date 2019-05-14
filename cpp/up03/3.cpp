#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string a;
    while(cin >> a) {
        int len = a.length();
        for(int i = 0; i < len; i++) {
            string x = a.substr(i);
            reverse(x.begin(), x.end());
            if(x == a.substr(i)) {
                cout << a.substr(i) << endl;
                break;
            }
        }
    }
}
