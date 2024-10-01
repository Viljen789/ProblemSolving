#include "/Users/vilje/Documents/GD/Unity/2021.3.18f1/PlaybackEngines/WebGLSupport/BuildTools/Emscripten/emscripten/cache/sysroot/include/c++/v1/bits/stdc++.h"
using namespace std;
#define ll long long
#define vl vector<ll>


int rc(ll n, ll a, ll b, ll c, ll k, vl &v){
	if(n<0)return 1e9;
	if(n==0)return k;
	if(v[n])return 1e9;
	v[n] = k;

	return min(rc(n-a, a, b, c, k+1, v), min(rc(n-b, a, b, c, k+1, v), rc(n-c,a, b, c, k+1, v)));
}

void solve(){
	ll n, a, b, c, k=0 ;cin>>n>>a>>b>>c;
	vl v(n, 0);
	ll ans = rc(n, a, b, c, k, v);
	// cout << ans << " ";
	cout << ((ans==1e9)?(-1):(ans));
}
int main(){
	solve();
	return 0;
}
	ll power(ll a, ll b)	//a is base, b is exponent
	{
		if(b==0)
			return 1;
		if(b==1)
			return a;
		if(b%2 == 1)
			return (power(a,b-1)*a)%mod;
		ll q = power(a,b/2);
		return (q*q)%mod;
	}