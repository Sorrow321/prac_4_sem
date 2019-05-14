#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Functor
{
    double sum = 0;
    int n = 0;
public:
    void operator () (double value)
    {
        sum += value;
        n++;
    }
    
    double get_mean() const
    {
        return sum / n;
    }
};

int main()
{
    double x;
    vector<double> data;
    while(cin >> x) {
        data.push_back(x);
    }
    
    double ssize = data.size();
    ssize *= 0.1;
    int size = (int)ssize;
    
    sort(data.begin() + size, data.end() - size);
    
    ssize = data.size() - 2 * size;
    ssize *= 0.1;
    size += (int)ssize;
    
    Functor obj;
    obj = for_each(data.begin() + size, data.end() - size, obj);
    
    cout << obj.get_mean() << endl;
}
