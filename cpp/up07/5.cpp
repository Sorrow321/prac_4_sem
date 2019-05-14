#include <complex>
#include <vector>
#include <utility>
#include <array>

constexpr size_t arr_len = 3;

namespace Equations
{
    using namespace std;
    template<typename T>
    pair<bool, vector<complex<T>>>
    quadratic(array<complex<T>, arr_len> v)
    {
        if(v[0] == complex<T>(0.0, 0.0) && v[1] == complex<T>(0.0, 0.0) && v[2] == complex<T>(0.0, 0.0)) {
            return pair<bool, vector<complex<T>>> (false, vector<complex<T>>());
        }else if(v[2] == complex<T>(0.0, 0.0) && v[1] == complex<T>(0.0, 0.0) && v[0] != complex<T>(0.0, 0.0)) {
            return pair<bool, vector<complex<T>>> (true, vector<complex<T>>());
        }else if(v[2] == complex<T>(0.0, 0.0) && v[1] != complex<T>(0.0, 0.0)) {
            vector<complex<T>> vec = { -v[0] / v[1] };
            return pair<bool, vector<complex<T>>> (true, vec);
        }else{
            complex<T> D = v[1] * v[1] - complex<T>(4.0, 0.0) * v[0] * v[2];
            vector<complex<T>> vec = { 
                (-v[1] + sqrt(D)) / (complex<T>(2.0, 0.0) * v[2]),
                (-v[1] - sqrt(D)) / (complex<T>(2.0, 0.0) * v[2])
            };
            return pair<bool, vector<complex<T>>> (true, vec);
        }   
    }   
}
