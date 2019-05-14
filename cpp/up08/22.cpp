#include <iostream>

using namespace std;
 
int check2(int zeros, int ones, bool& check, int ch)
{
    while (ch != EOF && !isspace(ch)){
        int z_ = 0, o_ = 0;
        while (ch != EOF && ch =='0'){
            z_++;
            ch = getchar();
        }
        while (ch != EOF && ch =='1'){
            o_++;
            ch = getchar();
        }
        if (zeros != z_ || ones != o_){
            check = false;
            return ch;
        }
    }
    return ch;
}

int main()
{
    int ch;
    while ((ch = getchar()) != EOF && isspace(ch)){}
    while (ch != EOF){
        int zeros = 0, ones = 0;
        while  (ch != EOF && ch == '0'){
            zeros++;
            ch = getchar();
        }
        while (ch != EOF && ch == '1'){
            ones++;
            ch = getchar();
        }
        bool check = true;
        if (!zeros || !ones){
            check = false;
        }
        if(check) {
            ch = check2(zeros, ones, check, ch);
        }
        cout << check << endl;
        
        
        while (ch != EOF && !isspace(ch)){
            ch = getchar();
        }
        while (ch != EOF && isspace(ch)){
            ch = getchar();
        }
    }
}
