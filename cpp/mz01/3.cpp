#include <iostream>

using namespace std;


int main()
{
    int n;
    cin >> n;
    
    Holder *arr = new Holder[n];
    for(int i = 0; 2*i < n; i++) {
        arr[i].swap(arr[n - i - 1]);
    }
    
    delete [] arr;
}
    
