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

int a[105];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			a[i]=0;
		}
		int u;
		for(int i=1;i<=n;i++){
			cin>>u;
			a[u]++;
		}
		int ans = 0; 
		for (int i=1;i<=2*n;i++){
			int k1 = 0;
			for(int j=1;j<i/2;j++){
				k1+= min(a[j],a[i-j]);
			}
			if(i&1){
				k1+=min(a[i/2],a[i/2+1]);
			}
			else{
				k1+=a[i/2]/2;
			}
			ans=max(ans,k1);
		}
		cout<<ans<<endl;
	}
	return 0;
}


