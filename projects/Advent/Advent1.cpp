///Users/vilje/Documents/TilfeldigeFiler/Python/RandomFiler/fil.txt
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
int main(){
    int f, s, t;
    ifstream file("/Users/vilje/Documents/TilfeldigeFiler/Python/RandomFiler/fil.txt");
    if (file.is_open()) {
        string line;
        int temp;
        while (std::getline(file, line)) {
            if(line == ""){
                if (temp > f){
                    t = s;
                    s = f;
                    f = temp;
                    

                } else if( temp > s){
                    t = s;
                    s = temp;
                } else if(temp > t){
                    t = temp;

                }
                temp = 0;
                continue;
            }
            temp += stoi(line);
            
    }
    file.close();
    cout << f+s+t << endl;
    return 0;
}
}