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

int a[2000];
int b[2000];
signed main(){
	int t;
	cin>>t;
	while(t--){
		
		
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		int f = 0;
		for(int i=1;i<=m;i++){
			cin>>b[i];
			for(int j=1;j<=n;j++){
				if(b[i]==a[j])f=a[j];
			}
		}
		if(f==0)cout<<"NO"<<endl;
		else cout<<"YES"<<"\n"<<1<<" "<<f<<endl;
		
		
	}
	return 0;
}


