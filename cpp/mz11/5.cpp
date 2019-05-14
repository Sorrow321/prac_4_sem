#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool is_var(char x){
    if('a' <= x && x <= 'z') {
        return true;
    }
    return false;
}

bool is_op(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/') {
        return true;
    }
    return false;
}

int main()
{
    stack<string> st;
    char c = getchar();
    while(c != EOF && isspace(c)) {
        c = getchar();
    }
    while(c != EOF) {
        if(is_var(c)) {
            st.push(string(1, c));
        }else if(is_op(c)){
            string c1 = st.top();
            st.pop();
            string c2 = st.top();
            st.pop();
            //cout << "(" << c2 << (char)c << c1 << ")";
            st.push("(" + c2 + (char)c + c1 + ")");
        }
        c = getchar();
        while(c != EOF && isspace(c)) {
            c = getchar();
        }
    }
    cout << st.top() << endl;
}
