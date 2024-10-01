using namespace std;
#define ll long long
#define vi vector<ll>


void solve(){
	ll t;cin>>t;
	ll n, s, e, w;
	bool found = false;
	ll ans = 0;
	for(int i = 0; i<t; i++){
		cin>>n>>s>>e>>w;
		if(w>=n)ans ++;
		if (s>e) {
			found = true;
		}
	}
			cout << "UGYLDIG"<<endl;
	if(found) 
	else cout << ans<<endl;
}
int main(){
	cout.tie(0);
	solve();
	return 0;
	

}