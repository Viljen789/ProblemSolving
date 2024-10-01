// Created by DD

#ifdef __APPLE__
#include "/Users/vilje/Documents/GD/Unity/2021.3.18f1/PlaybackEngines/WebGLSupport/BuildTools/Emscripten/emscripten/cache/sysroot/include/c++/v1/bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;
using namespace std::chrono;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define pb push_back
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define db(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define fix(prec) {cout << setprecision(prec) << fixed;}
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl

#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, false, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
typedef unordered_map<ll, ll> uml;
typedef unordered_map<char, ll> umcl;
typedef unordered_map<string, ll> umsl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define PI 3.1415926535897932384626433832795l 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 585;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

// -------------------------<RNG>------------------------- 
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.

void solve() {
// Add your solution herecc
	ll n, m;
	cin>>n>>m;
	vector<vl> partsums(m+1, vector<ll>(n+m,0));
	vl totsums(n+m,0);
	vector<vpl> dp(m, vpl(n));
	ll t;
	ll totneg = 0;
	ll negind = -1;
	for(int i = n-1; i>=0; i--){
		cin>>t;
		// if(t<0)totneg+=t;
		// t = abs(t);
		partsums[0][i] = t;
		if(i<m&&t<0)totneg+=t;
		if(t<0){
			if(negind == -1)negind = i;

		}
		else negind = -1;
		// deb2(negind, i);


	}
	// cout << negind;
	partsums[1] = partsums[0];
	partsums[1][0] = partsums[0][0];
	totsums[0] = partsums[0][0];
	for (int i = 1; i < n; ++i){
		totsums[i] = totsums[i-1]+(partsums[0][i]);
	}
	//totsums
	for(int i = 1; i<=m; i++){
		for(int j = 0; j<=i-1; j++){
			partsums[i][j] = totsums[j];
		}
	}
	for(int i = 0; i<n; i++){
        for(int j = 1; j<=m; j++){
            if(!partsums[j][i])partsums[j][i] = totsums[i]-totsums[i-j];
        }
    }
   

	for (int i = 0; i < m; ++i) {
	    priority_queue<int, vector<int>, greater<int>> pq;
	    for (int j = 0; j < m; ++j) {
	        pq.push(partsums[0][j]);
	        if (pq.size() > i+1) {
	            pq.pop();
	        }
	        dp[i][j].f = 0;
	        priority_queue<int, vector<int>, greater<int>> temp = pq;
	        while (!temp.empty()) {
	        	// if(temp.top()<0)totneg+=temp.top();
	        	if(temp.top()<0)dp[i][j].s+=temp.top();
				else dp[i][j].f += temp.top();
				// dp[i][j].s += temp.top()*(temp.top()<0);
	            // dp[i][j].f += temp.top();
	            // db(temp.top());
	            temp.pop();
	        }
	    }
	}
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			dp[j][i].s = totsums[i]-dp[j][i].f;
			// if(partsums[0][i]<0)dp[j][i].s+=2*abs(partsums[0][i]);

		}
	}
	
    // db(dp);
	for (int i = m; i < n; i++)
	{
		if(negind!=-1&&m>1){
	    	for (int i = 0; i <= m; ++i)
	    	{
	    		dp[m-1][i] = dp[m-2][i];
	    	}
	    }
		if(partsums[0][i]<=0)dp[0][i].s+= partsums[0][i];
		dp[0][i].f = max(dp[0][i-1].f, dp[m-1][i-1].s+partsums[0][i]);
		dp[0][i].s = totsums[i]-dp[0][i].f;
		for (int j = 1; j < m; ++j)
		{
			if(partsums[0][i]<=0){
				// deb3(dp[j][i].f, dp[j][i].s, partsums[0][i]);
				dp[j][i].f = dp[j][i-1].f;
				dp[j][i].s= dp[j][i-1].s+partsums[0][i];
				// deb3(dp[j][i].f, dp[j][i].s, partsums[0][i]);
				
			}
			else{
				dp[j][i].f = max(dp[j][i-1].f, dp[j-1][i-1].f+partsums[0][i]);
				dp[j][i].s = totsums[i]-dp[j][i].f;

			}
		}
	}
	db(dp);
	
	cout << dp[m-1][n-1].f<<" "<<dp[m-1][n-1].s;

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    clock_t z = clock();
    #ifdef __APPLE__
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int tc=1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
    cerr << "Run Time : " << ((double)(clock()-z)/CLOCKS_PER_SEC);
}
