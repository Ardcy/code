#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define int long long
typedef vector<int> VI;
typedef pair<int,int> PII;
const int mod = 1000000007;
int pb(int a,int b) {int res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a*=a;a%=mod;}return res;}
int a[105000];
int b[105000];
int c[105000];
VI P[105000];
set<int>Pr;
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)c[i]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			cin>>b[i];
		}
		int ans = n+1;
		for(int i=1;i<=n;i++){
			if(c[i]==1)continue;
			
			c[i]=1;
			int yu=i;
			int uy = b[i];
			P[uy].push_back(yu);
			int cnt = 1;
			int f = 0;
			for(int j=a[i];j!=yu;j=a[j]){
				cnt++;
				P[b[j]].push_back(j);
				c[j]=1;
				if(b[j]!=uy)f=1;
			}
			int mi=cnt;
			for(auto p:P){
				if(SZ(p)>1){
					sort(p.begin(),p.end());
					int q=SZ(p);
					for(int i=0;i<q;i++){
						int huu=p[i+1]-p[i];
						mi=min(huu,cnt-huu);	
					}
					mi=min(abs(p[q-1]-p[0]),cnt-abs(p[q-1]-p[0]));
				}
			}
			
			cout<<"cnt="<<cnt<<endl;
			ans=min(ans,cnt);
			if(f==0)ans=1;
			
		}
		cout<<ans<<endl;
		
	}
}
