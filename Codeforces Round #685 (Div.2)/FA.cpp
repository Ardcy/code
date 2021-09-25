#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5+5;
int arr[N];
const int mod = 1e9+7;
int qp(int a,int b){
	int ans = 1;
	while(b){
		if(b&1){
			ans *= a,ans%=mod;
		}
		a*=a,a%=mod;
		b>>=1;
	}
	return ans;
}

signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=2;i<=n;i++){
			cout<<i<<" ";
		}cout<<1<<endl;
	}
} 
