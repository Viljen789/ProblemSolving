#include "/Users/vilje/Documents/GD/Unity/2021.3.18f1/PlaybackEngines/WebGLSupport/BuildTools/Emscripten/emscripten/cache/sysroot/include/c++/v1/bits/stdc++.h"
using namespace std;

#define ll long long
#define vl vector<ll>
#define f first
#define s second
void solve(){
	cin>>n;
	vl v(n);
	map<ll, ll> um;
	for(int i = 0; i<n; i++){
		cin>>v[i];
		um[v[i]]++;
	}
	sort(v.begin(), v.end());
	for(auto i = um.end(); i!=um.begin(); i++){
		if()
	}

}

int main(){
	ll t; cin>>t;
	while(t--)solve();
}