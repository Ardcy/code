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
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int num1 = c-a;
		int num2 = d-b;
		if(num1==0||num2==0){
			cout<<1<<endl;
			continue;
		}
		int  sum = num1+num2;
		int m = max(num1,num2)-min(num1,num2);
		m = min(num1,num2)*m;
		int n = (min(num1,num2))*min(num1,num2)+1;
		cout<<(n+m)<<endl;
	}
	return 0;
}


