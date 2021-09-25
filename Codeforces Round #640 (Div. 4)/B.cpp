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
		
		if(n>=2*k&&(n-2*k+2)%2==0){
			cout<<"YES"<<endl;
			for(int i=1;i<k;i++){
				cout<<2<<" ";
			}
			cout<<n-2*k+2<<endl;
		}else if(n>=k&&(n-k+1)%2==1){
			cout<<"YES"<<endl;
			for(int i=1;i<k;i++){
				
				cout<<1<<" ";
			}
			cout<<n-k+1<<endl;
		}else
		cout<<"NO"<<endl;
		
		
		
	}
	return 0;
}


