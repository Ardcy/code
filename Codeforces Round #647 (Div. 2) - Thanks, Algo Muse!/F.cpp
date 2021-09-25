#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;}return ans;};


signed main(){
	
	
	
	int cnt = 0;
	for(int i=1;i<=10;i++){
		for(int j=i;j<=10;j++){
			for(int k=j;k<=10;k++)for(int l=k;l<=10;l++)cnt++;
		}
	}
	cout<<cnt<<endl;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
	}
	return 0;
}


