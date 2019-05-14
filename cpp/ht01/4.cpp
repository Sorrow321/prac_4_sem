#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <future>
#include <iomanip>

using namespace std;

typedef unsigned int ui;
constexpr ui radius = 50; // радиус круга, половина стороны квадрата

struct data_
{
    ui inside;
    ui total;
    data_& operator+=(data_ t) {
        inside += t.inside;
        total += t.total;
        return *this;
    }
};

data_ work(ui tid, ui it_num)
{
    data_ d{0, it_num};
    for(ui i = 0;  i < it_num; i++) {
        ui rx = rand_r(&tid) % (2 * radius) - radius;
        ui ry = rand_r(&tid) % (2 * radius) - radius;
        if(rx * rx + ry * ry <= radius * radius) {
            d.inside++;
        }
    }
    return d;
}

int main(int argc, char* argv[])
{
    stringstream ss;
    ss << argv[1] << " " << argv[2];
    ui thread_num, it_num;
    ss >> thread_num >> it_num;
    
    vector<future<data_>> f(thread_num);
    for(ui i = 0; i < thread_num; i++) {
        f[i] = async(launch::async, work, i, it_num); 
    }
    
    data_ res{0, 0};
    for(ui i = 0; i < thread_num; i++) {
        res += f[i].get();
    }
    cout << setprecision(5) << (double)res.inside / res.total  * 4 << endl;
}
