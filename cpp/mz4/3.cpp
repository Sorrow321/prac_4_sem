#include <vector>
#include <functional>

template <typename ForwardIterator, typename F>
auto myapply(ForwardIterator start, ForwardIterator finish, F func)
{
    for(auto it = start; it != finish; ++it) {
        func(*it);
    }
}

template <typename ForwardIterator, typename F>
auto myfilter2(ForwardIterator start, ForwardIterator finish, F func)
{   
    typedef std::reference_wrapper<typename std::iterator_traits<ForwardIterator>::value_type> ref;
    std::vector<ref> v;
    for(auto it = start; it != finish; ++it) {
        if(func(*it)) {
            v.insert(v.end(), *it);
        }
    }
    return v;
}
