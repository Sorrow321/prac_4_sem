constexpr int two = 2;

template<typename T>
auto process(const T &x)
{
    int j{0};
    typename T::value_type sum = {};
    if(x.begin() == x.end()) {
        return sum;
    }
    auto it = x.end();
    --it;
    for(; it != x.begin(); --it, ++j) {
        if(j == 0 || j == two || j == two * two) {
            sum += *it;
        }
    }
    if(j == 0 || j == two || j == two * two) {
        sum += *x.begin();
    }
    
    return sum;
}
