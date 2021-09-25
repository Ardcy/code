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
set<int>Pr;
signed main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		Pr.clear();
		int k;
		int f=0,df = 1;
		for(int i=1;i<=n;i++){
			cin>>k;
			int ans = 1e9;
			int d;
			for(int j=1;j<=k;j++){
				cin>>d;
				if(Pr.find(d)==Pr.end())ans=min(ans,d);
			}
			if(ans!=1e9)Pr.insert(ans);
			else f=1,df=i;
			
		}
		if(f==0)cout<<"OPTIMAL"<<endl;
		else{
			int yu;
			for(int i=1;i<=n;i++)if(Pr.find(i)==Pr.end()){
				yu=i;break;
			}
			cout<<"IMPROVE"<<endl;
			cout<<df<<" "<<yu<<endl;
		}
		
	}
}
