#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 1e9+7;
const int N = 200500;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;}return ans;};
int inv[N],fac[N],rev[N];
void init(int n){
	fac[0]=1;rev[n]=1;
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	rev[n]=qp(fac[n],mod-2);
	for(int i=n-1;i>=0;i--)rev[i]=rev[i+1]*(i+1)%mod;
	for(int i=1;i<n;i++)inv[i]=(rev[i]*fac[i-1]%mod)%mod;
}

int n;
vector<int>P[N];


int cnt = 0;
int b[N];
int numnode[N];
void dfs(int no, int pre){
	for(auto p:P[no]){
		if(p!=pre)
		{
			dfs(p,no);
			numnode[no]+=numnode[p];
		}
	}
}
void dfs2(int no,int pre){
	
	
	
	for(auto p:P[no]){
		
		if(p!=pre){b[++cnt] =(n-numnode[p])*numnode[p];
			dfs2(p,no);
		}		
	}
}
int a[N];
signed main(){
	int t;
	cin>>t;
	while(t--){
	
		cnt = 0;
		cin>>n;	for(int i=1;i<=n;i++)P[i].clear(),numnode[i]=1,a[i]=0;
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			P[u].pb(v),P[v].pb(u);
		}
		for(int i=1;i<=n;i++)numnode[i]=1;
//		int leaf1 = 0;
//		for(int i=1;i<=n;i++){
//			if(P[i].size()==1){
//				leaf1 = i;
//				break;
//			}
//		}
		int m;
		cin>>m;
		for(int i=1;i<=m;i++){
			cin>>a[i];
		}
		sort(a+1,a+m+1,greater<int>());
		if(m<=n-1)	
        {
        	for(int i=m+1;i<n;i++)a[i]=1;
		}
        else{
        	sort(a+1,a+m+1,greater<int>());
        	int d = n-1;
        	for(int i=1;i<=m-d;i++)a[1]*=a[i+1],a[1]%=mod;
        	for(int i=2;i<=d;i++)a[i]=a[i+m-d];
		}
		
		dfs(1,0);
		dfs2(1,0);
	//	cout<<cnt<<endl;
		sort(b+1,b+cnt+1,greater<int>());
		int ans = 0;
		//for(int i=1;i<=cnt;i++)cout<<b[i]<<" ";cout<<endl;
		for(int i=1;i<=cnt;i++){
			ans+=b[i]*a[i];
			ans%=mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}


