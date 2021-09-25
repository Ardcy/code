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

char P[100][100];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		getchar();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				P[i][j]=getchar();
			}getchar();
		}
		for(int i=1;i<=n;i++){
			P[n+1][i]='1';
			P[i][n+1]='1';
		}
		int f = 1;
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(P[i][j]=='1'){
					if(P[i][j+1]=='0'&&P[i+1][j]=='0')f=0;
				}
			}
		}
		if(f)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}


