#include <iostream>
#include <vector>
#include <future>

using namespace std;

bool is_prime(uint64_t a)
{
    if(a == 0 || a == 1) {
        return false;
    }
    for(uint64_t i = 2; i * i <= a; i++) {
        if(!(a % i)) {
            return false;
        }
    }
    return true;
}

void work(uint64_t low, uint64_t high, uint32_t count, vector<promise<uint64_t>>& p)
{
    uint32_t c = 0;
    try{
        for(uint64_t i = low; i <= high; i++) {
            if(is_prime(i)) {
                p[c].set_value(i);
                if(++c == count) {
                    break;
                }
            }
        }
        if(c < count) {
            throw high;
        }
    }catch(...) {
        p[c].set_exception(current_exception());
    }
}

int main()
{   
    uint64_t low, high;
    uint32_t count;
    
    cin >> low >> high >> count;
    
    vector<promise<uint64_t>> p(count);
    vector<future<uint64_t>> f(count);
    for(uint32_t i = 0; i < count; i++){
        f[i] = p[i].get_future();
    }
    
    thread th;
    try{
        th = thread(work, low, high, count, ref(p));
        for(uint32_t i = 0; i < count; i++) {
            cout << f[i].get() << endl;
        }
    }catch(uint64_t exc){
        cout << exc << endl;
    }
    th.join();
}
