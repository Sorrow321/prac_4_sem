#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

class NDFA
{
    multimap<pair<int, string>, int> *rules;
    vector<int> *term_states;
    int current_state;
    size_t pos;
    int symbols = 0;
    bool extra_term = false;
    bool good = false;
public:
    NDFA(multimap<pair<int, string>, int> *rules_, vector<int> *term_states_, int start_state, size_t pos_ = 0)
    : rules{rules_}, term_states{term_states_}, current_state{start_state}, pos{pos_} {}
    
    void handle(const string& str)
    {
        symbols = pos;
        if(pos == str.length()) {
            good = (int)(find(term_states->begin(), term_states->end(), current_state) != term_states->end());
            return;
        }
        
        bool not_found = true;
        typedef multimap<pair<int, string>, int>::iterator MMAPIterator;
        pair<MMAPIterator, MMAPIterator> result = 
        rules->equal_range(make_pair(current_state, string(1, str[pos])));
        for (MMAPIterator it = result.first; it != result.second; it++) {
            not_found = false;
            NDFA x(rules, term_states, it->second, pos + 1);
            x.handle(str);
            if(x.get_result()) {
                symbols = str.length();
                good = true;
                return;
            }else{
                if(symbols < x.get_symbols()) {
                    symbols = x.get_symbols();
                }
            }
        }
        if(!good) {
            pair<MMAPIterator, MMAPIterator> result = rules->equal_range(make_pair(current_state, "eps"));
            for (MMAPIterator it = result.first; it != result.second; it++) {
                not_found = false;
                NDFA x(rules, term_states, it->second, pos);
                x.handle(str);
                if(x.get_result()) {
                    symbols = str.length();
                    good = true;
                    return;
                }else{
                    if(symbols < x.get_symbols()) {
                        symbols = x.get_symbols();
                    }
                }
            }
        }
        
        if(not_found) {
            extra_term = true;
            return;
        }
    }
    
    int get_result() const
    {
        if(extra_term) {
            return 0;
        }
        return (int)good;
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
    multimap<pair<int, string>, int> rules;
    
    string prev, next;
    string val;
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
    
    NDFA x(&rules, &term_states, first_state_id);
    
    
    string input;
    cin >> input;
    x.handle(input);
    cout << x.get_result() << endl << x.get_symbols() << endl;
}
