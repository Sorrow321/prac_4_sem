#include <thread>

using namespace std;

template<typename Fu, typename Fuu, typename... Args>
void async_launch(Fu f, Fuu g, Args... args)
{
    thread th([](Fu f, Fuu g, Args... args){g(f((args)...));}, f, g, (args)...);
    th.detach();
}
