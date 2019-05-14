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

bool is_not_terminal_ch(char x)
{
    return ('A' <= x && x <= 'Z');
}

int main()
{
    string lhs, rhs;
    bool left_linear = true;
    bool right_linear = true;
    bool left_auto = true;
    bool right_auto = true;
    
    bool not_decreasing = true;
    bool first_in_right = false;
    bool extra_rule = false;
    bool has_replace = false;
    
    while(cin >> lhs >> rhs) {
        if(lhs == "S" && rhs.length() == 1 && is_not_terminal_ch(rhs[0])) {
            has_replace = true;
        }
        // проверка на праволинейность
        // A -> wB | w    A,B \in N    w \in T*
        if(is_not_terminal_ch(rhs[rhs.length() - 1])) {
            if(!is_terminal(string(rhs.begin(), rhs.end() - 1))) {
                right_linear = false;
            }
        }else if(!is_terminal(rhs)) {
            right_linear = false;
        }
        
        // проверка на леволинейность
        // A -> Bw | w    A,B \in N    w \in T*
        if(is_not_terminal_ch(rhs[0])) {
            if(!is_terminal(string(rhs.begin() + 1, rhs.end()))) {
                left_linear = false;
            }
        }else if(!is_terminal(rhs)) {
            left_linear = false;
        }
        
        // проверка на правоавтоматность
        // A - > aB | a   A,B \in N    a \in T
        if(rhs.length() > 2) {
            right_auto = false;
        }else if(rhs.length() == 2) {
            if(!is_not_terminal_ch(rhs[1]) || is_not_terminal_ch(rhs[0])) {
                right_auto = false;
            }
        }else if(rhs.length() == 1) {
            if(is_not_terminal_ch(rhs[0])) {
                right_auto = false;
            }
        }
        
        // проверка на левоавтоматность
        // A - > Ba | a   A,B \in N    a \in T
        if(rhs.length() > 2) {
            left_auto = false;
        }else if(rhs.length() == 2) {
            if(!is_not_terminal_ch(rhs[0]) || is_not_terminal_ch(rhs[1])) {
                left_auto = false;
            }
        }else if(rhs.length() == 1) {
            if(is_not_terminal_ch(rhs[0])) {
                left_auto = false;
            }
        }
        
        if(rhs == "_") {
            if(lhs == "S") {
                extra_rule = true;
            }else{
                not_decreasing = false;
            }
        }
        if(lhs.length() > rhs.length()) {
            not_decreasing = false;
        }
        
        if(contains_s(rhs)){
            first_in_right = true;
        }
    }
    
    if(not_decreasing && ((extra_rule && !first_in_right) || !extra_rule)) {
        // неукорачивающая
        if(!left_linear && !right_linear) {
            // неукорачивающая и не регулярная
            cout << 21 << endl;
            return 0;
        }
    }else{
        // не является неукорачивающей
        if(!left_linear && !right_linear) {
            // не является неукорачивающей и не регулярная
            cout << 2 << endl;
            return 0;
        }
    }
    
    if(left_linear) {
        // леволинейная
        if(!left_auto) {
            cout << 31 << endl;
            return 0;
        }
    }
    
    if(right_linear) {
        // праволинейная
        if(!right_auto) {
            cout << 32 << endl;
            return 0;
        }
    }
    
    if(right_auto && ((extra_rule && !first_in_right && has_replace) || !extra_rule)){
        // правоавтоматная
        cout << 321 << endl;
        return 0;
    }
    if(left_auto && ((extra_rule && !first_in_right && has_replace) || !extra_rule)){
        // левоавтоматная
        cout << 311 << endl;
        return 0;        
    }
}
