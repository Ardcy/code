#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 1e9+7;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%mod;a*=a,a%=mod;b>>=1;}return ans;};
int maxn = 1e6+5000;
int g[1050000];
signed main(){
	
	for(int i=2;i<=maxn;i++){
		if(g[i]==0)
		for(int j=i;j<=maxn;j+=i){
			g[j]=j/i;
		}
	}
	//cout<<g[49]<<endl;
	//for(int i=1;i<=10;i++)cout<<g[i]<<endl;
	int l1,r1,l2,r3,l3,r2;
	cin>>l1>>r1>>l2>>r2>>l3>>r3;
	int ans = 0;
	int ie = 0;
	for(int i=max((long long)3,l1);i<=r1;i++){
		int n = i;
		int temp = g[i];
		int f = i;
		cout<<"i="<<i<<" g[i]="<<g[i]<<endl;
		while(temp!=1){
			int a,b,c;
			a=temp;
			b=a*a/2;
			c=b+1;
			cout<<(++ie)<<" "<<a<<" "<<b<<" "<<c<<endl;
			if(a>2&&b*n/a>=l2&&b*n/a<=r2&&c*n/a>=l3&&c*n/a<=r3)ans+=(a+b+c)*(n/a);
			//if(a==2)break;
			f/=temp;
			temp=g[f];
		}
		if(temp==1){
			int a,b,c;
			a=f;
			b=a*a/2;
			c=b+1;
			cout<<(++ie)<<" "<<a<<" "<<b<<" "<<c<<endl;
			if(a>2&&b*n/a>=l2&&b*n/a<=r2&&c*n/a>=l3&&c*n/a<=r3)ans+=(a+b+c)*(n/a);
		}
		cout<<"ans="<<ans<<endl;
		ans%=mod;
	} 
	cout<<ans<<endl;
}


