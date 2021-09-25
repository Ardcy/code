#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
int a[105000];
int qp(int a,int b){
	int ans = 1;
	while(b){
		if(b&1)ans*=a;
		a*=a;
		b>>=1;
	}
	return ans;
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans = 0;
		for(int i=2;i<=n;i++){
			int p = a[i]-a[i-1];
			int ans1 = 0;
			if(p>=0)continue;
			p=-p;
			ans1 = log2(p);
			ans=max(ans1+1,ans);
			a[i]+=p;
		}
		cout<<ans<<endl;
	}
	return 0;
}


