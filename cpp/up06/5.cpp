#include <iostream>
#include <string>
#include <cstring>


using namespace std;

struct StringData
{
    char *buf;
    int count;
    size_t len;
    
    StringData(char *b = nullptr, int c = 1, size_t l = 0) : buf{b}, count{c}, len{l} {}
};

class String
{
    StringData *data = nullptr;
public:
    String()
    {
        data = new StringData();
    }
    String(const String& x)
    {
        data = x.data;
        data->count++;
    }
    /*
    String(string &x) 
    {
        size_t len = x.length();
        char *buf = new char[len + 1];
        for(size_t i = 0; i < len; i++) {
            buf[i] = x[i];
        }
        data = new StringData(buf, 1, len);
    }*/
    String(const char *x)
    {
        size_t len = strlen(x);
        char *buf = new char[len + 1];
        for(size_t i = 0; i < len; i++) {
            buf[i] = x[i];
        }
        buf[len] = 0;
        data = new StringData(buf, 1, len);
    }
    ~String()
    {
        data->count--;
        if(data->count <= 0) {
            delete[] data->buf;
            delete data;
        }
    }
    String& operator=(const String& x)
    {
        if(this != &x) {
            data->count--;
            if(data->count <= 0) {
                delete[] data->buf;
                delete data;
            }
            
            data = x.data;
            data->count++;
        }
        return *this;
    }
    /*
    String& operator+=(const String& x)
    {
        size_t new_len = data->len + x.data->len;
        char *new_buf = new char[new_len + 1];
        for(size_t i = 0; i < data->len; i++) {
            new_buf[i] = data->buf[i];
        }
        for(size_t i = data->len; i < new_len; i++) {
            new_buf[i] = x.data->buf[i - data->len];
        }
        data->count--;
        if(!data->count) {
            delete[] data->buf;
            delete data;
        }
        data = new StringData(new_buf, 1, new_len);
        return *this;
    }*/
    String& operator+=(const char* x)
    {
        size_t new_len = data->len + strlen(x);
        char *new_buf = new char[new_len + 1];
        for(size_t i = 0; i < data->len; i++) {
            new_buf[i] = data->buf[i];
        }
        for(size_t i = data->len; i < new_len; i++) {
            new_buf[i] = x[i - data->len];
        }
        new_buf[new_len] = 0;
        data->count--;
        if(data->count <= 0) {
            delete[] data->buf;
            delete data;
        }
        data = new StringData(new_buf, 1, new_len);
        return *this;
    }
    char& operator[](size_t i)
    {
        if(data->count > 1) {
            size_t u = data->len;
            char *new_buf = new char[data->len + 1];
            for(size_t i = 0; i < data->len; i++) {
                new_buf[i] = data->buf[i];
            }
            data->count--;
            data = new StringData(new_buf, 1, u);
        }
        return data->buf[i];
    }
    const char operator[](size_t i) const
    {
        return data->buf[i];
    }
    operator string() const
    {
        return string(data->buf);
    }
    char *get_ad()
    {
        return data->buf;
    }
};

void foo(String b){
    cout << string(b) << endl;;
}

int main()
{
    String a = "hello, world!";
    
    foo(String("al"));
}
