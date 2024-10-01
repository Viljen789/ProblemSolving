#include <iostream>
using namespace std;


int length(char ar[]){
    int len = 0;
    for(int i = 0; ar[i] != '\0'; i++){
        len++;
    }
    return len;
}
void reverse(char ar[]){
    int s = 0;
    int e = length(ar)-1;
    while (s<e){
        swap(ar[s], ar[e]);
        s++;
        e--;
        }

    }



int main(){
    char ar[] = {'a','b','c','d','e','f','g'};
    reverse(ar);
    cout << ar;

}
