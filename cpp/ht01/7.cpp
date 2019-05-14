#include <thread>
#include <mutex>
#include <vector>
#include <functional>

using namespace std;

template<class Input, class Output, class Function, class Callback>
void async_vector(const vector<Input> ins, Function &&f, Callback &&c)
{
    static size_t counter = 0;
    static vector<Output> out;
    static mutex m;
    static auto fr = c;
    static auto g = [&](Output res)
    {
        m.lock();
        out.push_back(res);
        if(++counter == ins.size()) {
            const vector<Output> & cr = out;
            fr(cr);
        };
        m.unlock();
    };
    for(size_t i = 0; i < ins.size(); i++) {
        async_launch(function<Output(Input)>(f), function<void(Output)>(g), ins[i]);
    }
}
