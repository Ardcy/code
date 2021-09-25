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

int a[205000];
int d[30];
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=20;j++){
			if((1<<j)&a[i])d[j]++;
		}
	}
	int c = 0;
	for(int j=0;j<=20;j++){
		c=max(c,d[j]);
	}
	int ans = 0;
	for(int i=1;i<=c;i++){
		int ans1 = 0;
		
		for(int j=0;j<=20;j++){
			if(d[j])ans1+=1<<j,d[j]-=1;
		}
		ans+=ans1*ans1;
		
	}
	cout<<ans<<endl;
	return 0;
}


