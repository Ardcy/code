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
int a[205000];
int b[205000];
int vis[205000];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)vis[i]=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)cin>>b[a[i]];
	//	for(int i=1;i<=n;i++)cout<<b[i]<<" ";cout<<endl;
		int ans = 0;
		for(int i=1;i<=n;i++){
			
			if(vis[i]==0){
				vis[i]=1;
				int mi = i,ma = i;
				int f = i;
				while(b[f]!=i){
					mi=min(mi,b[f]);
					ma=max(ma,b[f]);
					ans+=abs(b[f]-f);	
					vis[b[f]]=1;f=b[f];
				}
				//cout<<ma<<" "<<mi<<endl;
				ans+=abs(b[f]-f);
			}
		}
		cout<<ans/2<<endl;
	}
	
	return 0;
}
 
 
