		// Created by DD

// #ifndef ONLINE_JUDGE
// #include "/Users/vilje/Documents/GD/Unity/2021.3.18f1/PlaybackEngines/WebGLSupport/BuildTools/Emscripten/emscripten/cache/sysroot/include/c++/v1/bits/stdc++.h"
// #else
#include <bits/stdc++.h>
// #endif

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

class Graph
{
	list<ll> *l;
	ll V;
	bool visited[MAX_N];
	ll parent[MAX_N];
	ll searcher;
	bool valid[MAX_N];
	bool inStack[MAX_N];
	stack<ll> pathStack;
	ll score[MAX_N]; 
	// bool visited[MAX_N];
	// ll parent[MAX_N];
	ll start= 0;


public:
	Graph(int V){
		this->V  = V;
		l = new list<ll>[V];
		vl p(V);
		memset(visited, false, sizeof(visited));
		memset(valid, true, sizeof(valid));
		memset(inStack, false, sizeof(inStack));
		memset(score, false, sizeof(score));
	}
	~Graph() {
        delete[] l;
    }
	void addEdge(ll x, ll y){
		l[x].pb(y);
		l[y].pb(x);
	}
	void dfs(ll x, ll par)
{
    visited[x]=true;
    parent[x] = par;
    inStack[x] = true;  // mark node x as in the DFS stack
    pathStack.push(x);  // push node x to the path stack


    for(auto& i : l[x])
    {
        if(visited[i]==false)
        {
            dfs(i, x);
        }
        else if(i!=parent[x]&&valid[x]&&inStack[i]){  // check if node i is in the DFS stack
            searcher = x;
            while(!pathStack.empty()){
                valid[pathStack.top()] = false;
                pathStack.pop();
            }
        }
    }

    if (!pathStack.empty() && pathStack.top() == x) {
        pathStack.pop();  // pop node x from the path stack
    }
    inStack[x] = false;  // unmark node x as it's being popped from the DFS stack
}
	void printvalids()	{
		for (int i = 0; i < V; ++i)
		{
			if(valid[i])cout << i <<endl;

		}
	}

	void startdfs(ll x, ll par){
				if(start)return;
				visited[x]=true;
    			parent[x] = par;
				for(auto& i : l[x])
				{
					if(visited[i]==false)
					{
						startdfs(i, x);
					}
					else if(i != parent[x]){
						searcher = x;
						while(searcher != i){
							searcher = parent[searcher];
						}
						memset(visited, false, sizeof(visited));
						memset(parent, false, sizeof(parent));
						start = searcher;
					}
				}
			}
	ll findstart(){
		startdfs(0, -1);
		return start;
	}
};


void solve() {
    // Add your solution here
    cin>>n>>m;
    Graph g(n);
    for (int i = 0; i < m; ++i)
    {
    	cin>>x>>y;
    	g.addEdge(x, y);
    }
    g.dfs(g.findstart(), -1);
    g.printvalids();

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    clock_t z = clock();
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif


    int tc=1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
    cerr << "Run Time : " << ((double)(clock()-z)/CLOCKS_PER_SEC);
}