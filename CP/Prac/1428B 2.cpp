#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<ll>

void solve(){
	ll n; cin>>n;
	vector<char> v(n);
	char c;
	bool r=false, l=false;
	ll tot = 0;
	for(int i = 0; i<n; i++)cin>>v[i];
	for (int i = 0; i < n; ++i){
		c = v[i];
		if(c=='<')l =true;
		if(c=='>')r =true;
		if(v[i]!='-'&&v[(i+1)%n]!='-')tot++;
	}
	if(l&&r)cout << n-tot<<endl;
	else cout << n<<endl;
	// cout << n<<v[0]<<endl;
}

int main(){
	ll t; cin>>t;
	while(t--)solve();
	return 0;
}