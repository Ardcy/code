#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5+5;
int arr[N];
const int mod = 1e9+7;
int qp(int a,int b){
	int ans = 1;
	while(b){
		if(b&1)ans*=a,a%=mod;
		a*=a,a%=mod;
		b>>=1;
	}
	return ans;
}
signed main(){
	cout<<qp(2,10)<<endl;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> arr[i];
		}
	}
}
