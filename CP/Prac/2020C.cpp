#include "/Users/vilje/Documents/GD/Unity/2021.3.18f1/PlaybackEngines/WebGLSupport/BuildTools/Emscripten/emscripten/cache/sysroot/include/c++/v1/bits/stdc++.h"
using namespace std;
#define ll long long
#define vl vector<ll>
void solve(){
	ll n;
	vl v(n);
	for(int i = 0; i<n; i++)cin>>v[i];


}
	ll gcd( ll a, ll b )
	{
		if(b==0)
		{
		     return a;
		}
		else
		{
		     return gcd( b, a%b );
		}
	}
	ll lcm (ll a, ll b)
	{
		return (a*b)/gcd(a,b);
	}
int main(){
	ll x, y; cin>>x>>y;
	cout << gcd(x, y);
	// solve();
}
