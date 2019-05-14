template<typename T, typename F>
auto myfilter(const T& x, F pred)
{
    T newobj;
    
    for(auto it = x.begin(); it != x.end(); ++it) {
        if(pred(*it)) {
            newobj.insert( newobj.end(), *it );
        }
    }
    
    return newobj;
}
