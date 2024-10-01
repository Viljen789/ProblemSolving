///Users/vilje/Documents/TilfeldigeFiler/Python/RandomFiler/fil.txt
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

//DEL 1
int different_strings(string str, string orgstr){
    for(int i = 1; i < 14; i++){ //DEL 1: i<4
    char c = str[0];
    str = str.substr(1, 14-i);//DEL 1: i<4


if(str.find(c)<str.length()){ //to find +
    return 0;
} else {
    
    //not found
}
}
cout << orgstr << endl;
    return 1;


}




int main(){

    
    ifstream file("./Advent6.txt");
    if (file.is_open()) {
        bool end = false;
        string line, tempstr;
        char tempchar;
        while (std::getline(file, line)) {
            for(int i = 0; i < line.size(); i++) {
                tempstr = line.substr(i, 14); //Del 1: (i, 14);
                if (different_strings(tempstr, tempstr)){
                    end = true;
                    cout << i+14; //DEL 1 : i+4
                    cout << tempstr;
                    break;
                    
                }
}
}
file.close();
}

    return 0;
}
