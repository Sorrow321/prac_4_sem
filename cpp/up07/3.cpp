#include <iostream>
#include <string>
#include <sstream>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace boost::gregorian;
using namespace std;

int main()
{
    string str;
    bool first = true;
    int sum = 0;
    date prev; 
    while(cin >> str) {
        int y, m, d;
        stringstream t(str);
        t >> y >> m >> d;
        m *= -1;
        d *= -1;
        date cur(y, m, d);
        if(!first) {
            sum += abs((cur - prev).days());
        }else{
            first = false;
        }
        prev = cur;
    }
    cout << sum << endl;
}
