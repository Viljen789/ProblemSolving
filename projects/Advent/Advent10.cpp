#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
std::vector<std::string> split(const std::string& input)
{
    std::istringstream iss(input);
    std::vector<std::string> words;
    std::string word;
    while (iss >> word)
    {
        words.push_back(word);
    }
    return words;
}

int main(){
    
    ifstream file("./Advent10.txt");
    if (file.is_open()) {
        std::string line;
        std::string temp_line;
        int cycle = 1, temp_strength;
        int tot = 0, strength = 0;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            while(iss >> temp_line ){
                
                
                
                if(((cycle-20)%40) == 0){
                    if(cycle == 20){
                        strength++;
                    }
                    tot+=cycle*strength;
                    cout << "******"<<cycle * strength << endl;
                    cout << "-----"<<strength << endl;
                    

                }
                cycle++;
                if(temp_line.length()!= 4){
                    strength+=stoi(temp_line);
                    cout << temp_line << endl;
                    //cout << strength << endl;

                }
                
                
                
                
                
                
                
            }
        }
    cout << tot << endl;
    file.close();
    return 0;

}
}
