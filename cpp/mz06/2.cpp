#include <iostream>

/* рекурсивная функция делает то, что написано в условии,
 * только вместо return я использую throw класса Result
 */

using namespace std;

class Result
{
public:
    long long value = 0;
};

void func(long long a, long long b, long long k)
{
    try {
        Result res;
        if(k == 0) {
            res.value = a + b;
        }
        if(k > 0 && b == 1) {
            res.value = a;
        }
        if(k > 0 && b > 1) {
            func(a, b - 1, k);
        }
        throw res;
    } catch(Result x) {
        if(b > 1 && k > 0) {
            func(a, x.value, k - 1);
        }else{
            throw x;
        }
    }
}

int main()
{
    long long a, b, k;
    
    while(cin >> a && cin >> b && cin >> k) {
        try {
            func(a, b, k);
        } catch(Result res) {
            cout << res.value << endl;
        }
    }
}
