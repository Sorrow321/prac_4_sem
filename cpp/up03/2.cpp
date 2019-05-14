#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void process(const vector<int> &a, vector<int> &b)
{
    vector<int> p(a);
    sort(p.begin(), p.end());
    auto new_end = unique(p.begin(), p.end());
    p.erase(new_end, p.end()); 
    
    auto it_index = p.begin();
    for(; it_index < p.end(); ++it_index) {
        if(*it_index >= 0) {
            break;
        }
    }
    
    int i = 0;
    int offset = 0;
    
    for(auto it = b.begin(); (it + offset) < b.end(); ++it, ++i) {
        bool row = false;
        if(it_index != p.end() && *it_index == i) {
            ++offset;
            ++it_index;
            row = true;
        }
        
        if(distance(it, b.end()) <= offset) {
            break;
        }
        *it = *(it + offset);
        if(row) {
            --it;
        }
    }
    b.resize(b.size() - offset);
}
