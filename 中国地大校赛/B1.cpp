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

int P[200][2];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n,x,m;
		cin>>n>>x>>m;
		int l=x,r=x;
		int c1,c2;
		for(int i=1;i<=m;i++){
			cin>>c1>>c2;
			if(c1>c2)swap(c1,c2);
			if((l>=c1&&l<=c2)||(r>=c1&&r<=c2)){
				l=min(c1,l);r=max(r,c2);
			}
			
		}
		cout<<(r-l+1)<<endl;
		
		
	}
	return 0;
}


