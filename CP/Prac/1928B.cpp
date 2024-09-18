#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long 
#define vi vector<ll>

/*
7
2
1 2
4
7 1 4 1
3
103 102 104
5
1 101 1 100 1
5
1 10 100 1000 1
2
3 1
3
1000000000 999999997 999999999

*/


void solve(){
    ll n;cin>>n;
    vi v(n);
    for(int i = 0; i<n; i++)cin>>v[i];
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(auto i : v)cout << i;
}


int main(){
    ll t;cin>>t;
    solve();
    return 0;
}