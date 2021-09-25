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
	int t;
	cin>>t;
	while(t--){
		int a,b,c,d=0;
		cin>>a>>b>>c;
		if(b==0){
			
			if(a)for(int i=1;i<=a+1;i++)cout<<0;
			if(c)for(int i=1;i<=c+1;i++)cout<<1;
			cout<<endl;
			continue;
		}
		if(b%2==0)b--,d=1;
		if(d)cout<<0;
		for(int i=1;i<=c;i++)cout<<1;
		for(int i=1;i<=b+1;i++){
			cout<<i%2;
		}for(int i=1;i<=a;i++)cout<<0;
		cout<<endl;
		
		
	}
	return 0;
}


