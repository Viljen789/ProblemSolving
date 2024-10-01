#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
int main(){
    
    ifstream file("./FIL.txt");
    if (file.is_open()) {
        string line;
        while (std::getline(file, line)) {
            //...
            
    }
    file.close();
    return 0;
}
}