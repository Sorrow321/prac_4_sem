#include <iostream>
#include <cstdio>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

struct pdata
{
    int n_iter, first_id, second_id;
    double first_sum, second_sum;
};

void work(int tid, vector<mutex>& m, vector<double>& acc, vector<pdata>& params)
{
    pdata& p = params[tid];
    for(int i = 0; i < p.n_iter; i++) {
        if(p.first_id <= p.second_id) {
            m[p.first_id].lock();
            m[p.second_id].lock();
        }else{
            m[p.second_id].lock();
            m[p.first_id].lock();
        }
        acc[p.first_id] += p.first_sum;
        acc[p.second_id] += p.second_sum;
        m[p.first_id].unlock();
        m[p.second_id].unlock();
    }
}

int main()
{
    int acc_count, thr_count;
    cin >> acc_count >> thr_count;       
    
    vector<double> acc(acc_count, 0);
    vector<thread> t(thr_count);
    vector<mutex> m(acc_count);
    vector<pdata> params(thr_count);
    for(int i = 0; i < thr_count; i++) {
        cin >> params[i].n_iter >> params[i].first_id >> params[i].first_sum >> 
        params[i].second_id >> params[i].second_sum;
        
        t[i] = thread(work, i, ref(m), ref(acc), ref(params));
    }
    
    for(int i = 0; i < thr_count; i++) {
        t[i].join();
    }
    
    for(int i = 0; i < acc_count; i++) {
        printf("%.10g\n", acc[i]);
    }
}
