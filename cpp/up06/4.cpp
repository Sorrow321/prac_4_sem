#include <cmath>
namespace Game
{
    template<typename T>
    class Cube
    {
    public:
        typedef T value_type;
        T x, y, z;
        
        Cube(T x_ = 0, T y_ = 0, T z_ = 0) : x{x_}, y{y_}, z{z_} {}
    };
    
    template<typename T>
    class Coord
    {
    public:
        typedef T value_type;
        T row, col;
        
        Coord(T x = 0, T y = 0) : row{x}, col{y} {}
        
        Cube<T> to_cube()
        {
            T x = col;
            T z = row - (col + (col&1)) / 2;
            T y = -x - z;
            return Cube<T>(x, y, z);
        }
    };
    
    template<typename T>
    T abs(T x)
    {
        if(x >= 0){
            return x;
        }
        return -x;
    }
    
    template<typename T>
    T dist(Coord<T> k, Coord<T> u, Coord<T> v)
    {
        Cube<T> a = u.to_cube();
        Cube<T> b = v.to_cube();
        return (abs(a.x - b.x) + abs(a.y - b.y) + abs(a.z - b.z)) / 2;
    }
}
