#include <iostream>
#include <string>
#include <vector>

using namespace std;

void bar(string &s, unsigned i)
{
    for (auto it : s) {
        it = '1';
    }
}
bool next(string &str, int i)
{
    char &value = str[i];
    if (value == '2' && (i == 0 || str[ i - 1] == '3'  || str[ i - 1] == '4')){
        value = '3';
        return true;
    }
    switch(value) {
    case '1':
        value = '2';
        return true;
    case '2':
        value = '2';
        return true;
    case '3':
        value = '4';
        return true;
    case '4':
        if(i <= 0) {
            return false;
        }else{
            bar(str, i);
            return next(str, i - 1);
        }
    }
    return true;

}
int main()
{
    int k;
    cin >> k;
    
    string str;
    for (int i = 0; i < k ; i++){
        str.push_back('1');
        cout << 1;
    }
    cout << endl;
    while (next(str, str.length() - 1)){
        cout << str << endl;
    }
    
    return 0;
}
