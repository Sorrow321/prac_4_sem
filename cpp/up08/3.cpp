#include <iostream>
#include <string>
using namespace std;
bool is_terminal(const string &s)
{
    for(size_t i = 0; i < s.length(); i++) {
        if('a' <= s[i] && s[i] <= 'z') {
        }else if('0' <= s[i] && s[i] <= '9') {
        }else{
            return false;
        }
    }
    return true;
}

bool contains_s(const string &s)
{
    for(size_t i = 0; i < s.length(); i++) {
        if(s[i] == 'S') {
            return true;
        }
    }
    return false;
}

int main()
{
    string left, right;
    bool has_start = false;
    bool has_anything = false;
    bool has_all_terminal = false;
    bool is_context_free = true;
    bool not_decreasing = true;
    bool first_in_right = false;
    bool extra_rule = false;
    while(cin >> left >> right) {
        has_anything = true;
        if(left == "S") {
            has_start = true;
        }
        if(is_terminal(left)) {
            has_all_terminal = true;
            break;
        }
        if(right == "_") {
            if(left == "S") {
                extra_rule = true;
            }else{
                not_decreasing = false;
            }
        }
        if(left.length() != 1 || is_terminal(left)) {
            is_context_free = false;
        }
        if(left.length() > right.length()) {
            not_decreasing = false;
        }
        if(contains_s(right)){
            first_in_right = true;
        }
        
    }
    if(!has_anything || !has_start || has_all_terminal) {
        cout << -1 << endl;
        return 0;
    }else if(is_context_free) {
        if(not_decreasing && ((extra_rule && !first_in_right) || !extra_rule)) {
            cout << 23 << endl;
        }else{
            cout << 2 << endl;
        }
    }else{
        cout << 10 << endl;
    }
    return 0;
}
