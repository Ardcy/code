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
int a[2000][2];
signed main(){
	int n;
	cin>>n;
	n--;
	int be,ma;
	cin>>be>>ma;
	a[be][0]=1; 
	int u;
	int t=0;
	int ff=1;
	for(int j=1;j<=n;j++){
		cin>>u;
		int f=0;
		for(int i=0;i<=ma;i++){
			if(a[i][t]==j){
				//cout<<i<<" "<<j<<endl;
				if(i+u<=ma)a[i+u][1-t]=j+1,f=1;
				if(i-u>-1)a[i-u][1-t]=j+1,f=1;
			}		
		}
		t=1-t;
		if(f==0)ff=0;
	}
	if(ff==0)cout<<-1<<endl;
	else{
		int ans=0;
		for(int i=0;i<=ma;i++){
			if(a[i][t]==n+1)ans=i;
		}
		cout<<ans<<endl;
	}
	return 0;
}
