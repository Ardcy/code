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

	int n,s;
	cin>>n>>s;
	if(n>s/2){
		cout<<"NO"<<endl;
	}	else{
		
		if(1){
			int a=s;
			for(int i=1;i<n;i++)cout<<2<<" ";
			cout<<(s-2*n+2)<<endl;
			cout<<1<<endl;
		}
		
	}

	return 0;
}


