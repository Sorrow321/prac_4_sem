#include <cstdio>
#include <thread>
#include <mutex>

using namespace std;

constexpr int loops = 1000000;
constexpr int n = 3;

double arr[n];
mutex m;

void work(int tid)
{
    for(int i = 0; i < loops; i++) {
        m.lock();
        arr[tid] += 100 * (tid + 1);
        arr[(tid + 1) % n] -= 100 * (tid + 1) + 1;
        m.unlock();
    }
}

int main()
{
    thread t[n];
    for(int i = 0; i < n; i++) {
        t[i] = thread(work, i);
    }
    for(int i = 0; i < n; i++) {
        t[i].join();
    }
    for(int i = 0; i < n; i++) {
        printf("%.10g\n", arr[i]);
    }
}
