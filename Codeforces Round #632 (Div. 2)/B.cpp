#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define int long long
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef double db;
const int mod = 1000000007;
int qp(int a,int b) {int res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a*=a;a%=mod;}return res;}
int a[105000];
int b[105000];
int c[105000][3];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)cin>>b[i];
		for(int i=1;i<=n;i++){
			c[i][1]=c[i-1][1];
			c[i][2]=c[i-1][2];c[i][3]=c[i-1][3];
			if(a[i]==-1)c[i][1]=1;
			if(a[i]==0)c[i][2]=1;
			if(a[i]==1)c[i][3]=1;
		}
		if(a[1]!=b[1]){
			cout<<"NO"<<endl;
			continue;
		}
		int mi=a[1],ma=a[1];
		int f=1;
		for(int i=n;i>=2;i--){
			int u;
			if(b[i]!=a[i]) u= (b[i] - a[i])/abs(b[i] - a[i]);
			else continue;
			//cout<<u<<" "<<i<<" "<<c[i-1][u+2]<<endl;
			if(c[i-1][u+2]!=1)f=0;
		}
		
		if(f)cout<<"YES"<<endl;else cout<<"NO"<<endl;
	} 
	return 0;
}
