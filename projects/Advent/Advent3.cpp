#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    ifstream file("/Users/vilje/Documents/TilfeldigeFiler/C++/projects/Advent/Advent3.txt");
    int tot;
    int c = 1;
    string temp_string1, temp_string2, temp_string3;
    if (file.is_open()) {
        
        int num;
        string line, templine;
        string alphabet_lower = "abcdefghijklmnopqrstuvwxyz";
        string alphabet_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        while (std::getline(file, line)) {
        switch(c){
            case(1):
                temp_string1 = line;
                break;
            case(2):
                temp_string2 = line;
                break;
            case(3):
                temp_string3 = line;
                break;
        }
        /*
        templine = line;
        int len = line.length()/2;
        string start = line.erase((len));
        string end = templine.erase(0, len);
        */
    if (c%3 == 0){
    for( char c : temp_string1) {
    if(temp_string2.find(c)<temp_string2.length()){
    if(temp_string3.find(c)<temp_string3.length()){
        if(alphabet_lower.find(c)<alphabet_lower.length()){

    num = int(c)-96;
    tot += num;
    break;
    //cout << c << " "<< num << endl;
        
}else{
    num = int(c)-38;
    tot += num;
    break;
    //cout << c << " "<< num << endl;
    }

    }
    
    }
    
  }
  c=1;

    }else{
        c++;
    }

  
    }     
   

    
}
cout << tot;

return 0;
}

/*
DEL 1

int main(){
    ifstream file("./Advent3.txt");
    int tot;
    if (file.is_open()) {
        int num;
        string line, templine;
        string alphabet_lower = "abcdefghijklmnopqrstuvwxyz";
        string alphabet_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        while (std::getline(file, line)) {
        templine = line;
        int len = line.length()/2;
        string start = line.erase((len));
        string end = templine.erase(0, len);
  for( char c : start) {
    if(end.find(c)<end.length()){
    if(alphabet_lower.find(c)<alphabet_lower.length()){

    num = int(c)-96;
    tot += num;
    break;
    //cout << c << " "<< num << endl;
        
}else{
    num = int(c)-38;
    tot += num;
    break;
    //cout << c << " "<< num << endl;
    }
    }
    
  }
  
    }     
   

    
}
cout << tot;

return 0;
}
*/
