#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
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
int A[300];
int B[300];
int C[300];
int d[202][202][202];
bool cmp(int x,int y){return x>y;}
signed main(){
	int a,b,c;
	cin>>a>>b>>c;
	for(int i=1;i<=a;i++)cin>>A[i];
	for(int i=1;i<=b;i++)cin>>B[i];
	for(int i=1;i<=c;i++)cin>>C[i];
	sort(A+1,A+a+1,cmp);sort(B+1,B+b+1,cmp);sort(C+1,C+c+1,cmp);
	
	int ans1 = 0;
	for(int i=0;i<=a;i++){
		for(int j=0;j<=b;j++){
			for(int k=0;k<=c;k++){
				d[i][j][k]=max({d[i][j][k],i&&j?d[i-1][j-1][k]+B[j]*A[i]:0,i&&k?d[i-1][j][k-1]+C[k]*A[i]:0,j&&k?d[i][j-1][k-1]+B[j]*C[k]:0});
				ans1 = max(ans1,d[i][j][k]);
			}
			
		}
	}
	
	
	
	cout<<ans1<<endl;
	return 0;
}


