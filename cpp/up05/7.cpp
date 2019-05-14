#include <iostream>
#include <vector>

using namespace std;

struct Coord
{
    int x = 0, y = 0;
    Coord(int a, int b) : x{a}, y{b} {}
    bool operator==(const Coord& t){
        if(x == t.x && y == t.y){
            return true;
        }
        return false;
    }
};

struct Tractor
{
    Coord current_pos = Coord(0, 0);
    Coord next_pos = Coord(0, 0);
    Tractor(int x, int y, int action) : current_pos{Coord(x, y)}
    {
        switch(action) 
        {
        case 1:
            // влево
            next_pos = Coord(current_pos.x - 1, current_pos.y);
            break;
        case 2:
            // вправо
            next_pos = Coord(current_pos.x + 1, current_pos.y);
            break;
        case 3:
            // вверх
            next_pos = Coord(current_pos.x, current_pos.y + 1);
            break;
        case 4:
            // вниз
            next_pos = Coord(current_pos.x, current_pos.y - 1);
            break;
        case 5:
            // на месте 
            next_pos = Coord(current_pos);
            break;
        }
    }
};
    
void process(int n, vector<Tractor>& data)
{
    for(int i = 0; i < n; i++) {
        Tractor& lhs = data[i];
        bool collision = false;
        for(int j = 0; j < n; j++) {
            if(i == j){
                continue;
            }
            Tractor& rhs = data[j];
            
            if(lhs.next_pos == rhs.next_pos) {
                collision = true;
                rhs.next_pos = rhs.current_pos;
            }
        }
        if(lhs.next_pos.x == 0 && lhs.next_pos.y != 0) {
            collision = true;
        }
        if(collision) {
            lhs.next_pos = lhs.current_pos;
        }
    }
}

int main()
{
    vector<Tractor> data;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        Tractor t(a, b, c);
        data.push_back(t);
    }
    
    process(n, data);
    
    for(int i = 0; i < n; i++) {
        cout << data[i].next_pos.x << " " << data[i].next_pos.y << endl;
    }
}
