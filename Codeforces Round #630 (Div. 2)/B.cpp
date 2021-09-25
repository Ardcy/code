#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
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
mt19937 mrand(random_device{}());
const int mod = 1000000007;
int rnd(int x){return mrand()%x;}
int pb(int a,int b) {int res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a*=a;a%=mod;}return res;}
int a[2000];
int b[2000];
int c[2000]={0};
int d[2000];
signed main(){
	int t;
	vector<int>p;
	for(int i=2;i<=1000;i++){
		if(b[i]==0)
		{
			p.pb(i);
			for(int j=2;j*i<=1000;j++){
				b[i*j]=1;
			}
		}	
	}
//	for(int i=1;i<=100;i++)cout<<b[i]<<" "; 
	for(auto q:p){
		if(q>41)break;
		for(int i=1;i<=1000;i++){
			if(b[i]==1&&c[i]==0&&i%q==0){
				c[i]=q;
//				cout<<i<<" "<<q<<endl;
			}
		}
	}
	cin>>t;
	while(t--){
		int n;
		cin>>n; 
		for(int i=1;i<=n;i++)cin>>a[i];
		map<int,int>q;
		int cnt1 = 0;
		for(int i=1;i<=n;i++){
			
			if(q[c[a[i]]]==0){
				q[c[a[i]]]=++cnt1;
			}
			d[i]=q[c[a[i]]];
		}
		cout<<cnt1<<endl;
		for(int i=1;i<=n;i++){
			cout<<d[i]<<" ";
		}
		cout<<endl;
	}

	return 0;
}
