#ifndef ONLINE_JUDGE
#include "/Users/vilje/Documents/GD/Unity/2021.3.18f1/PlaybackEngines/WebGLSupport/BuildTools/Emscripten/emscripten/cache/sysroot/include/c++/v1/bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif



using namespace std;

#pragma GCC optimize("Ofast,unroll-loops") 
#pragma GCC target("avx,avx2,fma") 

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define F first
#define S second
#define pb push_back
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

#define PI 3.1415926535897932384626433832795l 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

// -------------------------<RNG>------------------------- 
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.

void solve() {
    // Add your solution here
    int n, m, h, temp, placement = 1, passedtime = 0;
    cin >>n >>m >>h;
    vector<vector<int>> timepp(n);
   	vector<pair<int, ll>> score(n);
    for(int i = 0; i<n; i++){
    	timepp[i].resize(m);
    }
    for (int i = 0; i < n; ++i)
    {
    	for (int ii = 0; ii < m; ++ii)
    	{
    		cin>>timepp[i][ii];
    	}
    }
    for (int i = 0; i < n; ++i)
    {
    	sort(all(timepp[i]));
    }
    for (int i = 0; i<timepp.size(); i++){
    	temp = h;
    	passedtime = 0;

    	for(auto ii: timepp[i]){
    		if(temp-ii>=0){
    			score[i].F++;
    			temp-=ii; 
    			passedtime += ii;
    			score[i].S += passedtime;
    			//cout <<i<<":"<<  score[i].S << endl;
    		}

    	}
    }
    //cout <<endl<< "R: "<<score[0].F <<"|"<<score[0].S << endl;

    for(int i = 1; i<n; i++){
    	//cout << i << ":"<<score[i].F <<"|"<<score[i].S << endl;
    	if(score[i].F>score[0].F){
    		placement++;
    	}else if(score[i].F==score[0].F&&score[i].S<score[0].S){
    		placement++;
    	}
    }
    cout << placement << endl;
}



int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        //cout << "Case #" << t << ": ";
        solve();
    }
}
