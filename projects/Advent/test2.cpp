#include <iostream>
#include <string>

using namespace std;

int main()
{
    int z = 123;
    int x = 10, y = 4;
    for(int i = 0; i<x; i++){
        if(i > z){
            break;
        }
        cout << i << " ";
        if(i == x-1){
            cout << "hasd" << endl;
        }
}
return 0;
}