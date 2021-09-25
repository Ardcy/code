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

int f(int a){
	return a*(a*3+1)/2;
}
int b[105000];
signed main(){
	int t;
	cin>>t;
	for(int i=1;i<=1e5;i++){
		b[i]=f(i);
	}
	while(t--){
		int n;
		cin>>n;
		int cnt = 0;
		while(n>=2){
			
			n-=b[upper_bound(b+1,b+100000,n)-b-1];
			cnt++;
		}
		
		cout<<cnt<<endl;
		
	}
	return 0;
}


