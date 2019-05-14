#include <new>
#include <utility>
namespace numbers
{
    class complex_stack
    {
        static constexpr size_t default_capacity = 8;
        size_t ssize = 0;
        size_t capacity = default_capacity;
        complex* stack = nullptr;
    public:
        void clear()
        {
            for (size_t i = 0; i < ssize; i++) {
                stack[i].~complex();
            }
            ::operator delete[](stack);
        }
        void make_move(complex_stack& x)
        {
            clear();
            ssize = 0;
            capacity = default_capacity;
            stack = static_cast<complex*>(::operator new[](capacity * sizeof(complex)));

            std::swap(ssize, x.ssize);
            std::swap(capacity, x.capacity);
            std::swap(stack, x.stack);
        }
        complex_stack(size_t size_ = 0, size_t capacity_ = default_capacity) : ssize{ size_ }, capacity{ capacity_ }
        {
            stack = static_cast<complex*>(::operator new[](capacity * sizeof(complex)));
        }
        complex_stack(const complex_stack& x) : ssize{ x.ssize }, capacity{ x.capacity }
        {
            stack = static_cast<complex*>(::operator new[](capacity * sizeof(complex)));
            for (size_t i = 0; i < ssize; i++) {
                new (stack + i) complex(x.stack[i]);
            }
        }
        complex_stack(complex_stack&& x)
        {
            make_move(x);
        }
        ~complex_stack()
        {
            clear();
        }
        complex_stack& operator=(const complex_stack& x)
        {
            if (this != &x)
            {
                clear();
                ssize = x.ssize;
                capacity = x.capacity;
                stack = static_cast<complex*>(::operator new[](capacity * sizeof(complex)));
                for (size_t i = 0; i < ssize; i++) {
                    new (stack + i) complex(x[i]);
                }
            }
            return *this;
        }
        complex_stack& operator =(complex_stack&& x)
        {
            if (this != &x) {
                make_move(x);
            }
            return *this;
        }
        complex_stack operator<<(const complex& x) const
        {
            complex_stack temp(ssize + 1, capacity);
            if (temp.capacity < temp.ssize) {
                temp.capacity *= 2;
            }
            temp.clear();
            temp.stack = static_cast<complex*>(::operator new[](temp.capacity * sizeof(complex)));
            for (size_t i = 0; i < ssize; i++) {
                new (temp.stack + i) complex(stack[i]);
            }
            new (temp.stack + ssize) complex(x);
            return std::move(temp);
        }
        complex_stack operator~() const
        {
            complex_stack temp(*this);
            temp.stack[--temp.ssize].~complex();
            return std::move(temp);
        }
        complex& operator [](size_t i) const
        {
            return stack[i];
        }
        complex& operator+() const
        {
            return stack[ssize - 1];
        }
        size_t size() const
        {
            return ssize;
        }
    };
};