#include <iostream>
using namespace std;
#define ll long long 

void solve(){
    ll a, b; cin>>a>>b;
    if(((min(a, b)==1)&&(max(a,b)&1))||((a&1)&(b&1))||(((min(a, b)*2 == max(a, b)))&&(min(a, b)&1)))cout <<"NO"<<endl;
    else cout << "YES"<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    ll t;cin>>t;
    while(t--)solve();
    return 0;
}
