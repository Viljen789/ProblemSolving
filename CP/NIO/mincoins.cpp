/*
5 8
########
#..#...#
####.#.#
#..#...#
########
*/



#include <iostream>
#include <vector>
#include <cmath>
#include <list>
#include <queue>
#define mp make_pair
using namespace std;

void dfs(int x, int y, vector<vector<bool> > &v){
	int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};
	v[x][y] = 0;
	for(int i = 0; i<4; i++){
		if(v[x+dx[i]][y+dy[i]]){
			dfs(x+dx[i], y+dy[i], v);
		}
	}
	
	

}


void solve(){
	int h, w;cin>>h>>w;
	vector<vector<bool> >v(h+2, vector<bool>(w+2, 0));
	char temp;
	for(int i = 1; i<h+1; i++){
		for(int j = 1; j<w+1; j++){
			cin>>temp;
			v[i][j] = (temp=='.');
		}
	}
	// for(auto i: v){
	// 	for(auto j: i)cout << j;
	// 	cout << endl;
	// }
	
	int counter = 0;
	for(int i = 1; i<h+1; i++){
		for(int j = 1; j<w+1; j++){
			if(v[i][j]){
				dfs(i, j, v);
				counter++;
			}
		}
	}
	cout << counter<< endl;
}

int main(){
	solve();
	return 0;
}