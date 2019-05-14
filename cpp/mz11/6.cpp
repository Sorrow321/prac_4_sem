#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;



int main()
{
    vector<string> vec;
    string s;
    while(cin >> s){
        vec.push_back(s);
    }
    map<string, int> mymap;
    
    size_t p = 0;
    for(size_t i = 0; i < vec.size(); i++) {
        if(vec[i][vec[i].length() - 1] == ':') {
            
            mymap.insert(make_pair(string(vec[i].begin(), vec[i].end() - 1), p + 1));
            p--;
        }
        p++;
    }
    
    
    for(size_t i = 0; i < vec.size(); i++) {
        if(vec[i][vec[i].length() - 1] == ':') {
            continue;
        }
        bool t = false;
        for(auto it = mymap.begin(); it != mymap.end(); it++) {
            if(it->first == vec[i]) {
                cout << it->second << endl;
                t = true;
                break;
            }
        }
        if(!t) {
            cout << vec[i] << endl;
        }
    }
}
