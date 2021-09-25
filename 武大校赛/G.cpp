#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
int a[1000];
signed main(){
	int n;
	cin>>n;
	int ma = -1e9;
	int u;
	for(int i=1;i<=n;i++){
		cin>>u;
		ma=max(u,ma);
	}
	cout<<ma<<endl;
	int mi  = 1e9;
	for(int i=1;i<=n;i++){
		cin>>u;
		mi=min(u,mi);
	}
	cout<<mi<<endl;
	int ans1 = ma+mi,ans=1e9;
	for(int i=1;i<=n;i++){
		cin>>u;
		if(abs(u+ans1)<abs(ans)){
			ans=u+ans1;
		}
	}
	cout<<ans<<endl;
	return 0;
}


