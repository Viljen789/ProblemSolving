#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	string alf = "abcdefghijklmnopqrstuvwxyz";
	bool ferdig = true;
	vector<int> bok;
	int c;
	while (ferdig){
		int temp;
		cout << "Skriv in tallet (q viss verdig)";
		cin >> temp;
		if(temp==100){
			ferdig = false;
		}
		else{
			bok.push_back(temp);
			c++;
		}
		
	}for(int i = 0; i<c; i++){
		cout << alf[bok[i]+1];
	}
}