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

int a[1005000];
int N = 1000000;


int b[200005];

int a1[200005];
int a2[200005];
int a3[200005];

int a4[200005];
int a5[200005];
int a6[200005];

int a7[200005];
int a8[200005];
int a9[200005];
signed main(){
	int t;
	
	for(int i=2;i<=N;i++)for(int j=i;j<=N;j+=i)if(a[j]==0)a[j]=i;
	//cout<<a[18]<<endl;
	cin>>t;
	
	while(t--){
		int n;
		cin>>n;
		int d,e,f;
		cin>>d>>e>>f;

		for(int i=1;i<=2*n;i++){
			a1[i]=0;a2[i]=0;a3[i]=0;
			a4[i]=0;a5[i]=0;a6[i]=0;
			a7[i]=0;a8[i]=0;a9[i]=0;
			b[i]=0; 
		}
		b[0]=0;
		for(int i=1,u;i<=n;i++){
			scanf("%lld",&u);
			b[i]=a[u]+b[i-1];
		}
		for(int i=1;i<=n;i++)b[i+n]=b[n];

		//for(int i=1;i<=2*n;i++)cout<<b[i]<<" ";cout<<endl;
		
		for(int i=1;i<=n;i++){
			a1[i]=b[i+d-1]-b[i-1];
			a2[i]=b[i+e-1]-b[i-1];
			a3[i]=b[i+f-1]-b[i-1];
		}		
		
		for(int i=1;i<=n;i++){
			a4[i]=max(a4[i-1],a1[i]);
			a5[i]=max(a5[i-1],a2[i]);
			a6[i]=max(a6[i-1],a3[i]);
		}
		for(int i=n;i>=1;i--){
			a7[i]=max(a7[i+1],a1[i]);
			a8[i]=max(a8[i+1],a2[i]);
			a9[i]=max(a9[i+1],a3[i]);
		}
		//for(int i=1;i<=n;i++)cout<<a8[i]<<endl;
		int ans = 0;
		
		//ans = max(solve(d,e,f),ans);
		
		// d e f
		int ans1 = 0;
		for(int i=d+1;i<=n-f-e+1;i++){	
			ans1 = max(a2[i]+a4[i-d]+a9[i+e],ans1);
		}
		ans = max(ans,ans1);
		
		//cout<<ans<<endl;
		
		//e d f
		ans1 = 0;
		for(int i=e+1;i<=n-f-d+1;i++){
			
			ans1 = max(a1[i]+a5[i-e]+a9[i+d],ans1);
		}
		ans = max(ans,ans1);
		//cout<<ans<<endl;
		//d f e
		ans1 = 0;
		for(int i=d+1;i<=n-e-f+1;i++){
			
			ans1 = max(a3[i]+a4[i-d]+a8[i+f],ans1);
		}
		ans = max(ans,ans1);
		//cout<<ans<<endl;
		//cout<<a3[2]<<" "<<a8[4]<<" "<<a4[1]<<endl;
		//e f d
		ans1 = 0;
		for(int i=e+1;i<=n-d-f+1;i++){
			
			ans1 = max(a3[i]+a5[i-e]+a7[i+f],ans1);
		}
		ans = max(ans,ans1);
		//cout<<ans<<endl;
		//f d e
		ans1 = 0;
		for(int i=f+1;i<=n-d-e+1;i++){
			
			ans1 = max(a1[i]+a6[i-f]+a8[i+d],ans1);
		}
		ans = max(ans,ans1);
		//cout<<ans<<endl;
		//f e d
		ans1 = 0;
		for(int i=f+1;i<=n-d-e+1;i++){
			
			ans1 = max(a2[i]+a6[i-f]+a7[i+e],ans1);
		}
		ans = max(ans,ans1);
		
		
		cout<<ans<<endl;
		
		
		
		
	}
	return 0;
}


