#include <iostream>
#include <string>
#include <

using namespace std;

class Account
{
    constexpr int DATA_SIZE = 4;
    uint32_t data[DATA_SIZE];
public:
    Account()
    {
        
    }
    
    Account(const Account& acc)
    {
        for(int i = 0; i < DATA_SIZE; i++) {
            data[i] = acc.data[i];
        }
    }
    
    Account(string str)
    {
        if(str == "0") {
            for(auto &i : data){
                i = 0;
            }
            return;
        }
        
        for(int i = 1; i < DATA_SIZE + 1; i++) {
            int len = str.length();
            string x = str.substr(len - DATA_SIZE * i);
            
            
        }
    }
    
    uint32_t Account(const uint32_t *data)
    {
        
    }
    
    const uint32_t* cdata() const
    {
        const uint32_t *p = data;
        return p;
    }
    
    string to_string() const
    {
        
    }
    
    
