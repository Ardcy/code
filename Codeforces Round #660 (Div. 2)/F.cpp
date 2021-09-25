
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
		int n;
		cin>>n;
		if(n>=31&&(n!=36&&n!=40&&n!=44))cout<<"YES"<<"\n"<<(6)<<" "<<10<<" "<<14<<" "<<(n-30)<<endl;
		else if(n>=31&&(n==36||n||40&&n||44))cout<<"YES"<<"\n"<<(6)<<" "<<10<<" "<<15<<" "<<(n-31)<<endl;
		else cout<<"NO"<<endl; 
	}
	return 0;
}


