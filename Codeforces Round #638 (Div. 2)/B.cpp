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

int p[200];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		
		
		cin>>n>>k;for(int i=1;i<=n;i++)p[i]=0;
		int u;
		for(int i=1;i<=n;i++){
			cin>>u;
			p[u]=1;
		}
		vector<int>P;
		int cnt = 0;
		for(int i=1;i<=n;i++){
			if(p[i])cnt++,P.pb(i);
		}
		
		
		if(cnt>k)cout<<-1<<endl;else{
			cout<<k*n<<endl;
			for(int i=1;i<=n;i++){
				if(!p[i]&&cnt<k)P.pb(i),cnt++;
			}
			for(int i=1;i<=n;i++){
				for(auto p1:P)cout<<p1<<" ";
			}
			cout<<endl; 
		}
		
	}
	return 0;
}


