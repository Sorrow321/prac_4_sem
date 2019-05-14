#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Factory
{
private:
    Factory() {}
    ~Factory() = delete;
public:
    static Factory& factory_instance()
    {
        static Factory x;
        return x;
    }
    
    Figure* create_object(string a)
    {
        istringstream stream(a);
        char x;
        stream >> x;
        switch(x)
        {
            case 'R':
            {
                double a, b;
                stream >> a >> b;
                
                ostringstream strs;
                strs << a;
                string str1 = strs.str();
                ostringstream strs2;
                strs2 << b;
                string str2 = strs2.str();
                
                Rectangle *rec = Rectangle::make(str1 + ' ' + str2);
                return rec;
            }
            case 'S':
            {
                double a;
                stream >> a;
                
                ostringstream strs;
                strs << a;
                string str1 = strs.str();
                
                Square *sq = Square::make(str1);
                return sq;
            }
            case 'C':
            {
                double r;
                stream >> r;
                
                ostringstream strs;
                strs << r;
                string str1 = strs.str();
                
                Circle *cir = Circle::make(str1);
                return cir;
            }
            default: 
                return nullptr;
        }
    }
};

bool compare_as_ints (double i,double j)
{
    return (int(i)<int(j));
}

bool compar(Figure *lhs, Figure *rhs)
{
    return lhs->get_square() < rhs->get_square();
}

int main()
{
    Factory mmm = Factory::factory_instance();
    
    string a;
    vector<Figure*> kek; 
    while(getline(cin, a))
    {
        kek.push_back(mmm.create_object(a));
    }
    
    stable_sort(kek.begin(), kek.end(), compar);
    
    for(auto it = kek.begin(); it != kek.end(); ++it)
    {
        cout << (*it)->to_string() << endl;
    }
}
