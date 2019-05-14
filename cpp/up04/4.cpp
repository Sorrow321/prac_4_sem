#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

template<typename T, typename K>
auto myremove(T beg_ind, T end_ind, K beg_el, K end_el)
{
    vector<int> ind(beg_ind, end_ind);
    unique(ind.begin(), ind.end());
    sort(ind.begin(), ind.end());
    
    auto it_el = beg_el;
    auto it_ind = ind.begin();
    int offset = 0;
    for(int i = 0; ; i++) {
        while(*it_ind < i + offset) {
            ++it_ind;
            if(it_ind == ind.end()) {
                break;
            }
        }
        
        if(*it_ind == i + offset) {
            offset++;
            
            for(auto k = it_el; k != end_el - 1; ++k) {
                swap(*k, *(k + 1));
            }
        }
        ++it_el;
        if(it_el == end_el) {
            break;
        }
    }
    return it_el;
}

int main()
{
    vector<int> asd = {10, 20, 30, -1};
    vector<int> sad = {0, 1};
    auto p = myremove(sad.begin(), sad.end(), asd.begin(), asd.end());
    for(auto i = asd.begin(); i != p; i++) {
        cout << *i << endl;
    }
}
    
