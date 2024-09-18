#include "/Users/vilje/Documents/GD/Unity/2021.3.18f1/PlaybackEngines/WebGLSupport/BuildTools/Emscripten/emscripten/cache/sysroot/include/c++/v1/bits/stdc++.h"
using namespace std;

#define ll long long
#define vl vector<ll>
#define f first
#define s second

void solve(){
	ll n, k, temp; cin>>n>>k;
	vl pref(n, 0);	
	for(int i = 0; i<k; i++){
		cin>>temp;
		pref[temp]++;
	}
	for(int i = 1; i<n; i++){
		pref[i]+=pref[i-1];
		cout << pref[i]<<" ";
	}

}

int main(){
	ll t=1; 
	while(t--)solve();
	return 0;
}