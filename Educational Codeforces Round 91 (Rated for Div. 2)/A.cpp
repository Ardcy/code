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

int a[1050];
signed main(){
	int t;
	cin>>t;
	
	while(t--){
		int f = 0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		
		for(int i=n;i>=3;i--){
			
			if(a[i]!=n){
				cout<<"YES"<<endl;
				f=1;
				cout<<
			}
		}
		
	}
	return 0;
}


