        // Created by DD


#include <bits/stdc++.h>

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
const ll INF = 1e10;
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
ll binarysearchabove(vpl &above, ll h){
    ll l = 0, r = sza(above)-1, mid;
    while(l<r){
        mid = (l+r)/2;
        if(above[mid].s>h)l = mid;
        else r = mid;
    }
    return above[l].f;
}


void solve() {
    // Add your solution here
    cin>>n>>m;
    ll x, h;
    vl height(n+1);
    vpl towers(m);
    for (int i = 0; i < n; ++i)cin>>height[i];
    // height[0] = 0;
    height[n] = INF;
    vpl r(n); 
    vl sol(n);
    ll curheight = 0, curindex = 1, blockerindex = 0;
    r[0].f = 0;
    r[0].s = 0;
    vpl above; 
    vl blocked(n);
    // lage ei liste for alle som blocker meir enn input rangen, og så kan vi binary searche gjennom dei 
    // r[i].f er den fuste plassen du blir stoppa, og 
    //gå bort, dersom du blir blocka tar du og 
    ll curmax = 0;
    while(curindex!=n){
            curheight = height[curindex];
            curmax = max(curmax, curheight+ curindex);
            above.pb(mp(curindex, curmax));
            curindex++;
    }
    // sol[0] = 1;
    above.pb(mp(n-1, INF));
    deb2(above, sol);
    for (int i = 0; i < m; ++i)
    {
        cin>>x>>h;
        cout << "h:"<< h<< " :";
       cout << binarysearchabove(above, h)<<endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    clock_t z = clock();

    int tc=1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
    cerr << "Run Time : " << ((double)(clock()-z)/CLOCKS_PER_SEC);
}

