#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
int P[205000];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)P[i]=0;
		int u;
		for(int i=1;i<=n;i++){
			cin>>u;
			P[u]++;
		}
		int y = 0;
		for(int i=1;i<=n;i++){
			if(P[i])y++;
		}
		int ans = 0;
		for(int i=1;i<=n;i++){
			if(P[i]>1){
				ans=max(ans,min(y,P[i]-1));
			}
			ans = max(ans,min(y-1,P[i]));
		}
		cout<<ans<<endl;
		
		
	}
	return 0;
}


