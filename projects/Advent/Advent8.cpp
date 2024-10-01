///Users/vilje/Documents/TilfeldigeFiler/Python/RandomFiler/fil.txt
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

/*DEL 1
bool visual(int x, int y, char value, vector<string>row){
    if((x == 0)||(x == row[0].length()-1)||(y == 0) || (y == row[0].length()-1)){
        return true;
    }
    for(int i = 0; i<x; i++){
        if(row[y][i] >= value){
            break;
        }
        if(i == x-1){
            cout << value <<"--- "<< row[y][i]<<" _1_ "<<x << "," << y<< endl;
            return true;
        }

    }
    for(int i = 0; i<y; i++){
        if(row[i][x] >= value){
            break;
        }
        if(i == y-1){
            cout << value <<"--- "<< row[y][i]<<" _2_ "<<x << "," << y<< endl;
            return true;
        }
    }
    for(int i = row[0].length()-1; i>x; i--){
        if(row[y][i] >= value){
            break;
        }
        if(i == x+1){
            cout << value <<"--- "<< row[y][i]<<" _3_ "<<x << "," << y<< endl;
            return true;
        }
    }
    for(int i = row[0].length()-1; i>y ; i--){
        if(row[i][x] >= value){
            break;
        }
        if(i == y+1){
            cout << value <<"--- "<< row[y][i]<<" _4_ "<<x << "," << y<< endl;
            return true;
        }
    }
    return false;
}
*/
int range(int x, int y, char value, vector<string>row){
    int n,s,e,w,tot,i = 1;
    bool test = true;
    if((x == 0)||(x == row[0].length()-1)||(y == 0) || (y == row[0].length()-1)){
        return 0;
    }
    while(test){
        if((row[y][x-i] >= value)||(x-i == 0)){
            w = i;
            test = false;
        }
        i++;
        

    }
    i = 1;
    test = true;
    while(test){
        if((row[y-i][x] >= value)||(y-i==0)){
            n = i;
            test = false;
        }
        i++;
    }
    i = 1;
    test = true;
    while(test){
        if((row[y][x+i] >= value)||(x+i == row[0].length()-1)){
            e = i;
            test = false;
        }
        i++;
    }
    i = 1;
    test = true;
        if((row[y+i][x] >= value)||(y+i == row[0].length()-1)){
            s = i;
            test = false;
        }
        i++;
    }
    tot = n*s*e*w;
    
    return tot;
}





int main(){
    
    ifstream file("./Advent8.txt");
    if (file.is_open()) {
        string line;

        vector<string> row;
        //vector<int> row;

        int y, x, len, c, current_largest;
        while (std::getline(file, line)) {
            row.push_back(line);
            len = line.length();
            //...

    }
    
    for(int i = 0; i < row.size(); i++){
            for(int ii = 0; ii< row[i].size(); ii++){
                if(range(ii, i, row[i][ii], row) > current_largest){
                    current_largest = range(ii, i, row[i][ii], row);
                    //cout << current_largest << endl;
                    //cout << i+1<< "x " << ii+1 << "y" << endl;
                }
            }
        
    }

    file.close();
    cout << current_largest;
    return 0;
}
}