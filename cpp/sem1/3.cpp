#include <cstdlib> 
#include <cstring>
#include <cstdio>

int size;


struct String
{
    // правильно сразу же инициализировать при объявлении
    // uniform initializer
    size_t size{};
    char *str{};
    
    //String() = delete;
    String() = default;
    String(const String &a) = delete; // запрет копирования
    
    String(const char *a)   // как только появляется какой-то другой конструктор, компилятор автоматически не делает конструктор по умолчанию
    {                       // так что его придется явно дописывать
        if(str) {
            String::size = strlen(str);
            String::str = new char[String::size + 1];
            memcpy(String::str, str, String::size + 1);
        }
    
    }
/*
    String()
    {
        //printf("hello\n");
    }
*/
    void append(const char *str)
    {
        
    }
};

String s2;
String s3;

void init_str(String *dst, const char *str)
{
    dst->str = strdup(str);
    dst->size = strlen(str);
}

int main()
{
    
}
