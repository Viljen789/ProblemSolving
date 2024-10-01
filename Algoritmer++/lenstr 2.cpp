 #include<iostream>
 #include <cstring>

 using namespace std;

 

 int main(){
    char str1[100];
    char str2[100];
    cout << "Input to string 1 and 2: "<< endl;
    cin >> str1 >> str2;
   // cin >> str2;
    if (strcmp(str1, str2) == 0){
        cout << "equal";
    }else{
        cout << "not equal";
    }
    return 0;
    cin >> str1 >> str2;

 }