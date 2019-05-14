#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;
string a;

static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

int comp(const void * j, const void * i)
{
    int l = *(int*)i;
    int r = *(int*)j;
    
    char* rhs = &a[0] + r;
    char* lhs = &a[0] + l;
    
    return strcmp(rhs, lhs);
}

int main()
{
    getline(cin, a);
    rtrim(a);
    vector<int> vec;
    size_t len = a.length();
    for(size_t i = 0; i < len; i++) {
        vec.push_back(i);
    }
    qsort(&vec[0], len, sizeof(int), comp);//, comp);
    for(auto it : vec) {
        cout << it << endl;
    }
}
