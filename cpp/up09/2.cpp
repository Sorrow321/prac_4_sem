#include <iostream>
#include <string>

using namespace std;

class Analyzer
{
    char state = 'S';
    const string *input = nullptr;
    size_t pos = -1;
    bool result = true;
public:
    Analyzer(const string* x) : input{x}, pos{x->length() - 1}
    {
        analyze();
    }
    int get_result() const
    {
        return (int)result;
    }
    void analyze()
    {
        switch(state)
        {
        case 'S':
            if((input->at(pos) != '0' && input->at(pos) != '1') || !pos--) {
                result = false;
                return;
            }
            state = 'C';
            analyze();
            break;
        case 'C':
            if((input->at(pos) != '0' && input->at(pos) != '1') || !pos--) {
                result = false;
                return;
            }
            state = 'B';
            analyze();
            break;
        case 'B':
            if(input->at(pos) != '1') {
                result = false;
                return;
            }
            state = 'A';
            if(!pos--) {
                return;
            }
            analyze();
            break;
        case 'A':
            if(input->at(pos) != '0' && input->at(pos) != '1') {
                result = false;
                return;
            }
            if(!pos--) {
                return;
            }
            analyze();
            break;
        }
    }
};

int main()
{
    string str;
    while(cin >> str) {
        Analyzer a(&str);
        cout << a.get_result() << endl;
    }
}
