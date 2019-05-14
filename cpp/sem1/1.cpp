#include <cstdlib> 
#include <cstring>
#include <cstdio>

int size;

struct String
{
    size_t size;
    char *str;
    int count;
    
    String() // без параметров - конструктор по умолчанию
    { // String *this
        size = 0;
        // this->size = 0; // по факту это так
        // String::size
        // ::size - глобальная неименованная область видимости
        str = nullptr; // имеет тип nullptr_t
        printf("hello\n");
    }
    
    
};

String s2; // конструкторы будут вызываться по порядку. Если несколько файлов в проекте - порядок не определен
String s3;

void init_str(String *dst, const char *str)
{
    dst->str = strdup(str);
    dst->size = strlen(str);
}

int main()
{
    printf("main\n");
    String s1;
    printf("after s1\n");
    
    String *s4 = new String; // атомарная комбинация malloc и вызова конструктора
    
    String s5[16]; // для каждого эл-та этого класса будет вызван конструктор
    
    static String s7; // конструктор вызывается тогда, когда управление в 1 раз попадет на эту переменную, хотя память на неё выделена сразу
    // при повторных входах конструктор вызываться не будет (максимум 1 раз)
    /* if(s1.len == 128) {
     *     static String s7;  // тут не будет вызван вообще, тк условие не выполнено
     * }
    */
    
    
}
