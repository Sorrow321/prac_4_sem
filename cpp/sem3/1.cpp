#include <cstdlib>

class Integer
{
    int value;
public:
    const Integer &operator ++()
    {
        if (_builtin_add_overflow(value, 1, &value)) {
            abort();
        }
        return *this;
    }
    operator ++(int dummy) // постфикс
    {
        Integer tmp = *this;
        ++*this;
        return tmp;
    }
    
    // Например, для класса String
    /*
    char operator[] (size_t index) const
    {
        return str[index];
    }
    
    
    char &operator[] (size_t index)
    {
        return str[index];
    }
    */
    
    
};

int main()
{
    Integer g;
    ++g;
}
