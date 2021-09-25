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
	int n;
	cin>>n;
	cout<<(4+3*n)<<endl;
	
	cout<<"1 1"<<endl;
	cout<<"2 1"<<endl;
	cout<<"1 2"<<endl;
	cout<<"2 2"<<endl;
	for(int i=2;i<=n+1;i++){
		cout<<i<<" "<<i+1<<endl;
		cout<<i+1<<" "<<i<<endl;
		cout<<i+1<<" "<<i+1<<endl;
	}
	return 0;
}


