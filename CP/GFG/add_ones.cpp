#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
#define ll long long
#define vl vector<ll>
#define s second
#define mp make_pair
#define pb push_back

int sorty(pair<int, int> a, pair<int, int> b){
	return a.s<b.s;
}

void solve(){
    vector<pair<int, int> > v;
    v.pb(mp(1, 3));
    v.pb(mp(2, 5));
    v.pb(mp(3, 7));
    v.pb(mp(9, 1));
    v.pb(mp(3, 5));
    sort(v.begin(), v.end(), sorty);
    for(auto i: v)cout << i.first << " " << i.s<<endl;
}
int main() {
	ll tc; cin>>tc;
	while(tc--)solve();
	return 0;
}