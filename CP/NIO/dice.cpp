#include <iostream>
#include <vector>
using namespace std;
#define ll long long
void solve(){
	ll n;cin>>n;
	vector<ll>nums(6);
	ll const mod = 1e9+7;
	ll sum = 0;
	nums[0]=1;
	for(int i = 1; i<n; i++){
		sum = 0;
		for(int j = 5; j>0; j--){
			sum+=nums[j];
			nums[j] = nums[j-1];
			nums[j] %= mod;
		}
		nums[0]+=sum;
		nums[0]%=mod;
	}
	sum = 0;
	for(long long l : nums){
		sum+=l;
		sum%=mod;
	}
	cout << sum << endl;
}

int main(){
	ll tc = 1;
	while(tc--)solve();
	return 0;
}
//660641036

// if(i==6)tot--;
// 		if(i==7)tot--;
// 		if(i>=8){
// 			c*=2; 
// 			c%=mod;
// 			tot-=c;
// 			if(tot<0)tot+=mod;
// 		}
// 		cout << i+1 << " "<<tot << " " << c << " " << endl;
// 		tot%=mod;
// 	}
// 	cout << tot << endl;