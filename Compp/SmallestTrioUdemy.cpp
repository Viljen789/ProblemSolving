#ifndef ONLINE_JUDGE
#include "/Users/vilje/Documents/GD/Unity/2021.3.18f1/PlaybackEngines/WebGLSupport/BuildTools/Emscripten/emscripten/cache/sysroot/include/c++/v1/bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

#define pb push_back
using namespace std;

int minTrioDegree(int n, vector<vector<int>> edges){
	list<int> nl (n+1);
	vector<int> degree(n+1);
	for (auto p : edges){
		nl[p].pb()
	}
}