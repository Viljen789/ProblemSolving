#ifndef ONLINE_JUDGE
#include "/Users/vilje/Documents/GD/Unity/2021.3.18f1/PlaybackEngines/WebGLSupport/BuildTools/Emscripten/emscripten/cache/sysroot/include/c++/v1/bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif



using namespace std;


int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
	int i = 1;
	while(i){
		int harrald = 0;
		  for (int w = 1; i<sqrt(i-1); i++){
		  	if (i%w==0)harrald +=w;
		      if(w!=1)harrald +=i/w;
		  if(harrald == i)cout << (harrald) << endl;
		  i++;
		}
	}
	return 0; 
}
