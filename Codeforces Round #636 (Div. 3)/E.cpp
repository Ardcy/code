#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
int p[205000];
vector<int> P[205000];
int vis[205000],vis1[205000],vis2[205000];
int s[205000];
signed main(){
	int t;
	cin>>t;
	while(t--){
		
		int n,m,a,b,c;
		cin>>n>>m>>a>>b>>c;
		for(int i=1;i<=n;i++){
			P[i].resize(0);
			vis[i]=0,vis1[i]=0,vis2[i]=0;
		}
		for(int i=1;i<=m;i++)cin>>p[i];
		sort(p+1,p+m+1);
		int u,v;
		for(int i=1;i<=m;i++){
			cin>>u>>v;
			P[u].push_back(v);
			P[v].push_back(u);
		} 
		queue<int>Q;
		Q.push(a);
		vis[a]=1;
		int r = 1;
		int cu = 0;
		while(!Q.empty()&&r){
			int y = Q.front();
			Q.pop();
		//	cout<<y<<endl;
			for(auto p:P[y]){
				if(vis[p]==0)vis[p]=vis[y]+1,cu++,Q.push(p);
				if(cu==n-1){
					r=0;break;
				}
			}
		//	cout<<"iiiiiiiiiiiiii   "<<cu<<endl;
		}
		//for(int i=1;i<=n;i++)cout<<i<<" "<<vis[i]<<endl;
		int u1 = vis[b]-vis[a];
		queue<int>Q1;
		Q1.push(b);
		vis1[b]=1;
		int rr = 1;
		cu=0;
		while(!Q1.empty()&&rr){
			int y = Q1.front();
			Q1.pop();
			for(auto p:P[y]){
				if(!vis1[p])vis1[p]=vis1[y]+1,cu++,Q1.push(p);
				if(cu==n-1){
					rr=0;break;
				}
			}
		}
		
		int u2 = vis1[c]-vis1[b];
		
		queue<int>Q2;
		Q2.push(c);
		vis2[c]=1;
		cu=0;
		int rrr = 1;
		while(!Q2.empty()&&rrr){
			int y = Q2.front();
			Q2.pop();
			for(auto p:P[y]){
				if(!vis2[p])vis2[p]=vis2[y]+1,cu++,Q2.push(p);
				if(cu==n-1){
					rrr=0;break;
				}
			}
		}
		
		
//		int u3 = vis2[c]-vis2[a];cout<<u1<<" "<<u2<<" "<<u3<<endl;
//		int y4 = (u1+u2-u3)/2;
//		int y5= u3;
//		int ans = 0;
//		for(int i=1;i<=m;i++){
//			if(i<=y4)ans+=2*p[i];
//			if(i>y4&&y5){
//				ans+=p[i];
//				y5--;
//			}
//			
//		}
		int now;
		int ans = 1e18;
		for(int i=1;i<=m;i++)s[i]=s[i-1]+p[i];
		for(int i=1;i<=n;i++){
			if(vis[i]+vis1[i]+vis2[i]-3>m)continue;
			now = 2*s[vis1[i]-1];
			now+=s[vis[i]+vis2[i]+vis1[i]-3]-s[vis1[i]-1];
		//	cout<<now<<endl;
			ans=min(ans,now);
		}
		cout<<ans<<endl;
	}
	return 0;
}


