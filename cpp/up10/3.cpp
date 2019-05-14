#include <iostream>
#include <vector>
#include <string>

using namespace std;

constexpr size_t alphabet_size = 26;

size_t char_id(char c)
{
    return c - 'A';
}

void work(const vector<pair<string, string>> & data, vector<bool>& used, char sym)
{
    for(size_t i = 0; i < data.size(); i++) {
        if(data[i].first.at(0) == sym) {
            for(size_t j = 0; j < data[i].second.length(); j++) {
                char c = data[i].second.at(j);
                if('A' <= c && c <= 'Z' && !used[char_id(c)]) {
                    used[char_id(c)] = true;
                    work(data, used, c);
                }
            }
        }
    }
    
}

int main()
{    
    vector<pair<string, string>> data;
    vector<bool> used(alphabet_size, false);
    
    string lhs, rhs;
    while(cin >> lhs >> rhs) {
        data.push_back(make_pair(lhs, rhs));
    }
    
    used[char_id('S')] = true;
    work(data, used, 'S');
    
    for(size_t i = 0; i < data.size(); i++) {
        int c = data[i].first.at(0);
        if(used[char_id(c)]) {
            cout << data[i].first << " " << data[i].second << endl;
        }
    }
}
