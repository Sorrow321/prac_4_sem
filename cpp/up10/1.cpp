#include <iostream>
#include <string>
using namespace std;
void work(int k, int depth, string &str, bool blocked)
{
    if(k == depth) {
        cout << str << endl;
        return;
    }
    
    str[depth] = '1';
    work(k, depth + 1, str, true);
    
    str[depth] = '2';
    work(k, depth + 1, str, true);
    
    if(!blocked) {
        str[depth] = '3';
        work(k, depth + 1, str, false);
    
        str[depth] = '4';
        work(k, depth + 1, str, false);
    }
}

int main()
{
    int k;
    cin >> k;
    string str(k, '*');
    work(k, 0, str, false);
}
