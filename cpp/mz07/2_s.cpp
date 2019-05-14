#include <iostream>
#include <string>

using namespace std;

int main()
{
    string inp;
    cin >> inp;
    
    int count = 0;
    int first_pos = -1;
    for(int i = 0; i < (int)inp.length(); i++) {
        if(inp[i] == '1') {
            count++;
            if(first_pos == -1) {
                first_pos = i;
            }
        }
    }
    if(count % 2) {
        inp[first_pos] = '0';
    }
    cout << inp << endl;
    return 0;
}
