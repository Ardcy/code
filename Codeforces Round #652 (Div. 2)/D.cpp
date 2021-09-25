#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 1e9+7;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;}return ans;};

int F[2005000]={0};
signed main(){
	
	F[1]=0,F[2]=0,F[3]=4,F[4]=4;
	for(int i=5;i<=2005000;i++){
		F[i]=F[i-1]+2*F[i-2];
		if(i%3==0)F[i]+=4;
		
		F[i]%=mod;
	}
	int t;
	
	
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<F[n]<<endl;
	}
	return 0;
}


