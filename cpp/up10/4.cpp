#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

class DFA
{
    map<pair<int, char>, int> *rules;
    vector<int> *term_states;
    int current_state;
    size_t pos = 0;
    int symbols = 0;
    bool extra_term = false;
public:
    DFA(map<pair<int, char>, int> *rules_, vector<int> *term_states_, int start_state)
    : rules{rules_}, term_states{term_states_}, current_state{start_state} {}
    
    void handle(const string& str)
    {
        if(pos == str.length()) {
            return;
        }
        auto t = rules->find(make_pair(current_state, str[pos++]));
        if(t == rules->end()) {
            extra_term = true;
            return;
        }else{
            current_state = t->second;
        }
        handle(str);
        symbols++;
    }
    
    int get_result() const
    {
        if(extra_term) {
            return 0;
        }
        return (int)(find(term_states->begin(), term_states->end(), current_state) != term_states->end());
    }
    
    int get_symbols() const
    {
        return symbols;
    }
    
    int get_state_id() const
    {
        return current_state;
    }
    
};

int main()
{
    map<string, int> states;
    map<pair<int, char>, int> rules;
    
    string prev, next;
    char val;
    int state_id = 0;
    while(cin >> prev) {
        if(prev == "END") {
            break;
        }
        cin >> val >> next;
        int prev_id = -1, next_id = -1;
        if(states.find(prev) == states.end()) {
            states.insert(make_pair(prev, ++state_id));
            prev_id = state_id;
        }
        if(states.find(next) == states.end()) {
            states.insert(make_pair(next, ++state_id));
            next_id = state_id;
        }
        if(prev_id == -1) {
            prev_id = states.find(prev)->second;
        }
        if(next_id == -1) {
            next_id = states.find(next)->second;
        }
        rules.insert(make_pair(make_pair(prev_id, val), next_id));
    }
    
    string term_state;
    vector<int> term_states;
    while(cin >> term_state) {
        if(term_state == "END") {
            break;
        }
        term_states.push_back(states.find(term_state)->second);
    }
    
    string first_state;
    cin >> first_state;
    int first_state_id = states.find(first_state)->second;
    
    DFA x(&rules, &term_states, first_state_id);
    
    
    string input;
    cin >> input;
    x.handle(input);
    cout << x.get_result() << endl << x.get_symbols() << endl;
    for (auto it = states.begin(); it != states.end(); ++it) {
        if(it->second == x.get_state_id()) {
            cout << it->first << endl;
            return 0;
        }
    }
}
