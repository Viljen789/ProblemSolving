#define ll long long 
ll sqrt(ll x){
    ll i = 1;
    ll add = 1;
    while(i*i<=x)(i<<=1);
    (i>>=1);
    while(i*i<=x){
        add = 1;
        while((i+add)*(i+add)<=x){
            (add<<=1);
        }
        (add>>=1);
        if(!add)break;
        i = i|add;
        cout <<"i:"<<  i <<"add:"<<  add << endl;
    }
    cout << i << endl;
    return i;
}

class Solution {
public:
    int mySqrt(ll x) {
        return sqrt(x);
    }
};