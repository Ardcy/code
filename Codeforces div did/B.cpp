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

int b[100000];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int f = 1;
		for(int i=1,u;i<=n;i++){
			cin>>b[i];
			
		}
		
		for(int i=1;i<n;i++){
			if(b[i]==1)f=1-f;
			else break;
		}
		if(f==1)cout<<"First"<<endl;else cout<<"Second"<<endl;
	}
	return 0;
}


