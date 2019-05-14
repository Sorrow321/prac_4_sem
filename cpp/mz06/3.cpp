template<class T>
class Coord
{
public:
    typedef T value_type;
    T row, col;
    Coord() {}
    Coord(const Coord& kek)
    {
        row = kek.row;
        col = kek.col;
    }
    Coord(T x, T y)
    {
        row = x;
        col = y;
    }
    Coord(T x)
    {
        row = x;
        col = 0;
    }
};

template<typename T, typename K>
T min(T x, K y)
{
    if(x < y){
        return x;
    }
    return y;
}

template<typename T, typename K>
T max(T x, K y)
{
    if(x > y){
        return x;
    }
    return y;
}

template<typename T>
T abs(T x)
{

    if(x < 0){
        return -x;
    }
    return x;
}

template<typename T>
T dist(Coord<T> size, Coord<T> x, Coord<T> y)
{
    T w = size.col;
    T h = size.row;
    
    T lhs = min(abs(x.row - y.row), min(x.row + h - y.row, y.row + h - x.row));
    T rhs = min(abs(x.col - y.col), min(x.col + w - y.col, y.col + w - x.col));
    
    return max(lhs, rhs);
}
