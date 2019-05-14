#include <iostream>

using namespace std;

class S
{
private:
    int sum;
    bool output;
    bool empty;
public:
    S(S&& c)
    {
        sum = c.sum;
        c.output = false;
        empty = c.empty;

        int a;
        if (cin >> a) {
            sum += a;
            empty = false;
        }
        else {
            output = true;
        }
    }
    ~S()
    {
        if (!empty && output) {
            cout << sum << endl;
        }
    }
    S() : sum{ 0 }, output{ true }, empty{ true }
    {

    }

    explicit operator bool()
    {
        return !cin.eof();
    }
};