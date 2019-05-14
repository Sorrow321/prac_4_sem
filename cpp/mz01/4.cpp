#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int n{0};
    double sum{0};
    double sum_sqr{0};
    
    double a;
    while(cin >> a) {
        n++;
        sum += a;
        sum_sqr += a * a;
    }
    
    double avg = sum / n;
    double avg_sqr = sum_sqr / n;
    
    cout << setprecision(10) << avg << endl << sqrt(avg_sqr -  avg * avg) << endl;
    return 0;
}
