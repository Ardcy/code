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

int a[300][2];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int c;
		int c1 = 0, c2 = 0;
		for(int i=1;i<=200;i++)a[i][0]=0,a[i][1]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>c;
				if(c==1)a[j+i][0]+=1;else a[j+i][1]+=1;
			}
		}
		int ans = 0;
		for(int i=1;i<=(n+m-1)/2;i++){
			
			ans+=min(a[i+1][0]+a[n+m+1-i][0],a[i+1][1]+a[n+m+1-i][1]);
		//	cout<<ans<<endl;
		}
		cout<<ans<<endl;
		
	}
	return 0;
}


