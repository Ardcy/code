#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
int n,q,x,y,depth[1000010];
ll cnt[2];
int main(){
	cin>>n;
	for(int i = 1;i<=30;i++){
		debug(i);
		int u = i^1;
		debug((i^1));
		cout<<endl;
	}
	depth[1] = 0;
	cnt[0] = 1;
	for(int i=2;i<=n;i++){
		int cc;
		cin>>cc;
		debug(depth[cc]);
		depth[i] = depth[cc]^1;
		cnt[depth[i]]+=1; 
		
	}
	cout<<cnt[0]*(cnt[0]-1)+cnt[1]*(cnt[1]-1)<<endl; 
}
	
