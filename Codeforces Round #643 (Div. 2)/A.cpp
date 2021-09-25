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

int p(int n){
	int a1 = n;
	int a2=100,a3=0;
	while(a1){
		a2=min(a2,a1%10);
		a3=max(a3,a1%10);
		a1/=10;
	}
	
	return a2*a3+n; 
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
	
		for(int i=1;i<k;i++){
		{
		if(n==p(n))break;
		n=p(n);	
			
		}
		
		
		
	}cout<<n<<endl;
	}

	return 0;
}


