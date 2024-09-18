///Users/vilje/Documents/TilfeldigeFiler/Python/RandomFiler/fil.txt
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
int main(){
    ifstream file("./Advent2.txt");
    if (file.is_open()) {
        string line;
        int tot;
        while (std::getline(file, line)) {
            switch(line[0]){
                case 'A':
                    switch(line[2]){
                        case 'X':
                            tot+= 3;
                            break;
                            
                        break;
                        case 'Y':
                            tot+= 1;
                            break;
                        case 'Z':
                            tot+= 2;
                            break;
                        default:
                            cout << "Invalid choice" << endl;
                    }
                break;

                case 'B':
                    switch(line[2]){
                        case 'X':
                            tot+= 1;
                            break;
                        case 'Y':
                            tot+= 2;
                            break;
                        case 'Z':
                            tot+= 3;
                            break;
                        default:
                            cout << "Invalid choice" << endl;
                    }
                break;

                case 'C':
                    switch(line[2]){
                        case 'X':  
                            tot+= 2;
                            break;
                        case 'Y':
                            tot+= 3;
                            break;
                        case 'Z':
                            tot+=1;
                            break;

                        default:
                            cout << "Invalid choice" << endl;
                    }
                break;
                default:
                    cout << line[0] <<line[2] << endl;
            

            }
            
         
    if (line[2] == 'X'){
                tot += 0;
            }else if (line[2] == 'Y'){
                tot += 3;
            }else{
                tot += 6;
            }
  
    }
    cout << tot << endl;
    file.close();
    return 0;
    
   
    }
}


/*
DEL 1;
///Users/vilje/Documents/TilfeldigeFiler/Python/RandomFiler/fil.txt
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
int main(){
    ifstream file("./Advent2.txt");
    if (file.is_open()) {
        string line;
        int tot;
        while (std::getline(file, line)) {
            switch(line[0]){
                case 'A':
                    switch(line[2]){
                        case 'X':
                            tot+= 1;
                            tot+= 3;
                            break;
                            
                        break;
                        case 'Y':
                            tot+= 2;
                            tot+= 6;
                            break;
                        case 'Z':
                            tot+= 3;
                            tot+= 0;
                            break;
                        default:
                            cout << "Invalid choice" << endl;
                    }
                break;

                case 'B':
                    switch(line[2]){
                        case 'X':
                            tot+= 1;
                            tot+= 0;
                            break;
                        case 'Y':
                            tot+= 2;
                            tot+= 3;
                            break;
                        case 'Z':
                            tot+= 3;
                            tot+= 6;
                            break;
                        default:
                            cout << "Invalid choice" << endl;
                    }
                break;

                case 'C':
                    switch(line[2]){
                        case 'X':  
                            tot+= 1;
                            tot+= 6;
                            break;
                        case 'Y':
                            tot+= 2;
                            tot+= 0;
                            break;
                        case 'Z':
                            tot+= 3;
                            tot+= 3;
                            break;

                        default:
                            cout << "Invalid choice" << endl;
                    }
                break;
                default:
                    cout << line[0] <<line[2] << endl;

            }
            
         
    
  
    }
    cout << tot << endl;
    file.close();
    return 0;
    
   
    }
}
*/

