///Users/vilje/Documents/TilfeldigeFiler/Python/RandomFiler/fil.txt
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

std::vector<std::string> split(const std::string& str, char delim) {
    std::vector<std::string> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != std::string::npos) {
        end = str.find(delim, start);
        strings.push_back(str.substr(start, end - start));
    }
    return strings;
}


int main(){
    int counter;
    ifstream file("./Advent4.txt");
    if (file.is_open()) {
        int c;
        string line;
        while (getline(file, line)) {
                    const std::string str = line;

            std::vector<std::string> strings1 = split(str,'-');
            int start1 = stoi(strings1[0]), slutt2 = stoi(strings1[2]);
            
            std::vector<std::string> strings2 = split(strings1[1],',');
            int slutt1 = stoi(strings2[0]), start2 = stoi(strings2[1]);
            
            //cout << start2<<" "<<slutt2 << endl;
            //del denne opp og pluss på forskjellen
            /*
            DEL 1
            if (((start1>=start2)&&(slutt1<=slutt2))||((start2>=start1)&&(slutt2<=slutt1))){
                c++;
                cout << line << endl;
                
            }*/
            if (((start1>slutt2))||((start2>slutt1))){
                c++;
                cout << line << endl;

            }
            counter++;
    
            
            

            
    }
    cout <<counter - c << endl;
    file.close();
    return 0;
}
}