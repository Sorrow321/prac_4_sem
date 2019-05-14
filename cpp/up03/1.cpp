#include <iostream>
#include <vector>

using namespace std;

void process(const vector<int> &a, vector<int> &b, int c)
{
    if (b.empty()) {
        return;
    }
    auto it_a = a.begin();
    auto it_b = b.begin();

    while (it_a < a.end() && it_b != b.end()) {
        *it_b = *it_a;
        bool bad = false;
        for (int i = 0; i < c; i++) {
            if (it_a == a.end()) {
                bad = true;
                break;
            }
            ++it_a;
        }
        if (bad) {
            break;
        }
        ++it_b;
    }

    for (auto it = b.rbegin(); it != b.rend(); ++it) {
        std::cout << *it << std::endl;
    }
}