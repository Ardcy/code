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

int t = 600851475143;
//int a[105000];
signed main(){
//	int t=2;
	int f = 1;
	int p = sqrt(t);
	for(int i=2;i<=p;i++){
		while(t%i==0){
			f=max(i,f);
			t/=i;
		} 
	}
	cout<<max(f,t)<<endl;
	return 0;
}


