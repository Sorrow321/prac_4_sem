#include <iostream>

template<typename T>
auto sum(const T &v)
{
    typename T::value_type s{};
    
    for(const auto &x : v) {
        s +=x;
    }
    return s;
}

using namespace std;

int main()
{
    
}
