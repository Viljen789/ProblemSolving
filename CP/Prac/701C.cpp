#include"/Users/vilje/Documents/GD/Unity/2021.3.18f1/PlaybackEngines/WebGLSupport/BuildTools/Emscripten/emscripten/cache/sysroot/include/c++/v1/bits/stdc++.h"
using namespace std;
#define ll long long
#define vl vector<ll>

void solve(){
	ll n;cin>>n;
	string s; cin>>s;
	set<char> us; 
	unordered_map<char,int> um;
	for(int i = 0; i<n; i++){
		us.insert(s[i]);
	}
	for(auto i:us){
		um[i] = 0;
	}
	ll k = us.size();
	if(n==1){
		cout << n<<endl;
		return;
	}
	ll counter = 1;
	um[s[0]]++;
	ll l = 0, r = 1, ans = n;
	while(l<r){
		if(counter == k){
			ans = min(ans, r-l);
			ll++; 
			counter-=(--um[s[l]]==0);
		}else if(r!=n){
			counter+=(++um[s[++r]]==1);
		}else break;
		cout << counter << " "<< l<< " " << r<<endl;
	}
	cout << ans;
}


int main(){
	ll tc = 1;
	while(tc--)solve();
	return 0;
}

