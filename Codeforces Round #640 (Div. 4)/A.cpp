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
		vector<int>P;
		for(int i=1;i<=5;i++){
			if(n%qp(10,i)!=0){
				P.pb(n%qp(10,i));
				n-=n%qp(10,i);
				
			}
		}
		cout<<P.size()<<endl;
		for(auto p:P)cout<<p<<" ";cout<<endl;
		
	}
	return 0;
}


