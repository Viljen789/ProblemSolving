#include <iostream>
#include <vector>
using namespace std;

#define ll long long int

ll numofballs(int n, vector<int> a){
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += a[i];
    }
    ans = ans*(ans-1)/2;

    for (int i = 0; i < n; i++)
    {
        ans -= a[i]*(a[i]-1)/2;
    }
    return ans;
}

int main(){
    int n; cin >>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout << numofballs(n, a)<<endl;

    return 0;
}