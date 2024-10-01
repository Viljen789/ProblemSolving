#include <iostream>
#include <cstring>

using namespace std;

void string_copy(char org[], char dup[]){
    for (int i = 0; i<strlen(org); i++){
        dup[i] = org[i];
    }
    dup[strlen(org)] = '\0';


}
int main()
{
    char org[100];
    char dup[100];
    cin >> org >>dup;
    //string_copy(org, dup);
    strncpy(dup, org, 5);
    cout << org << " " << dup;
    return 0;
}