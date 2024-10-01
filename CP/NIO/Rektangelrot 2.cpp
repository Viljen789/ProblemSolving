#if __APPLE__
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
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl

#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, false, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define PI 3.1415926535897932384626433832795l 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

// -------------------------<RNG>------------------------- 
// RANDOM NUMBER GENERATOR
// mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
// #define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.

void solve() {
    // Add your solution here
    ll r1x1, r1y1, r1x2, r1y2, r2x1, r2y1, r2x2, r2y2;cin>>r1x1>> r1y1>> r1x2>> r1y2>> r2x1>> r2y1>> r2x2>> r2y2;

    // cout << w1 << " "<<l1 << " "<<w2 << " "<<l2 << " "<<endl;
    ll hor=0, vert=0;
    if(r1x1>r2x1){
        swap(r1x1, r2x1);
        swap(r1x2, r2x2);
        swap(r1y1, r2y1);
        swap(r1y2, r2y2);
    }
    ll w1 = r1x2-r1x1, l1 = r1y2-r1y1, w2=r2x2-r2x1, l2 = r2y2-r2y1;
    ll ar = 2*w1+2*l1+2*w2+2*l2;

    // db(l2);

    if(r2x1>r1x2){
        cout << ar;
        return;
    }
    else if (r2y2<r1y1||r2y1>r1y2){
        cout << ar;
        return;
    }
        
    else if(r2x2<r1x2){
        // vert = l2-((r1y1>r2y1)*(r1y1-r2y1)+(r2y2>r1y2)*(r2y2-r1y2));
        vert = l2;
        vert += (r1y1>r2y1)*(r1y1-r2y2)+ (r2y2>r1y2)*(r2y2-r1y2);
        hor = w2;
        // vert = l2;
    }

    else if(r2x2>=r1x2){
        // vert = r1x2-r2x1;
        hor = r1x2-r2x1;
        if(r2y2>=r1y2&&r2y1<=r1y1)vert = l1;
        else if(r2y2>=r1y2)vert = r1y2-r2y1;
        else if(r2y1<=r1y1)vert = r2y2-r1y1;
        else vert = l2;
    }


    deb3(ar,hor, vert);
    cout << ar-2*(hor+vert) << endl;
}

int main() {
    #if __APPLE__
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}