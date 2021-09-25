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


signed main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		if(k<n)cout<<k<<endl;
		else if(k%(n-1)==0){
			cout<<k/(n-1)*n-1<<endl;
		}else
		cout<<k/(n-1)*n+(k)%(n-1)<<endl;
	}
	return 0;
}


