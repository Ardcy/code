#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int arr[N+5];
const int mod = 998244353;
int qp(int a,int b){
	int ans = 1;
	while(b){
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod;
		b>>=1;
	}
	return ans;
}
signed main(){
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 2;
	for(int i=4;i<=200050;i++){
		arr[i] = (arr[i-1] + arr[i-2] )%mod;
	}
	int n;
	cin>>n;
	cout<< arr[n] *qp(qp(2,n),mod-2)%mod<<endl;
	return 0;
}
