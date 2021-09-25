#include<bits/stdc++.h>
using namespace std;
const int MAXN = 110;
int n,m,mapp[MAXN][MAXN];
bool vis[MAXN],connect[MAXN][MAXN];
int dis[MAXN],maxd[MAXN][MAXN],per[MAXN];
#define INF 0x3f3f3f3f
void Init(){
	memset(mapp,INF,sizeof(mapp));
	memset(connect,false,sizeof(connect));
}
int prim(){
	memset(maxd,0,sizeof(maxd));
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;i++){
		dis[i]=mapp[1][i];per[i]=1;
	}
	vis[1]=1;
	dis[1]=0;
	int res=0;
	for(int i=1;i<n;i++){
		int index=-1,temp=INF;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&dis[j]<temp){
				index=j;temp=dis[j];
			}
		}
		if(index==-1)return res;
		vis[index]=1;
		connect[index][per[index]]=maxd[index][per[index]]=temp;
		res+=temp;
		maxd[per[index]][index]=maxd[index][per[index]]=temp;
		for(int j=1;j<=n;j++){
			if(j!=index&&vis[j]){
				maxd[index][j]=maxd[j][index] = max(maxd[j][per[index]],dis[index]);
			}
			if(!vis[j]&&mapp[index][j]<dis[j]){
				dis[j]=mapp[index][j];
				per[j]=index;
			}
		}
	}
	return res;
}
int main(){
	int T;
	scanf("%d\n",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		Init();
		int u,v,w;
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&u,&v,&w);
			mapp[u][v]=w;mapp[v][u]=w;
			connect[u][v]=true;
			connect[v][u]=true;
		}
		int ans = prim();
		bool over = false;
		for(int i=1;!over&&i<=n;i++){
			for(int j=1;j<=n;j++){
				if(connect[i][j]==false||mapp[i][j]==INF)continue;
				if(mapp[i][j]==maxd[i][j]){
					over=1;break;
				}
			}	
		}
		if(over){printf("Not Unique!\n");
		}else printf("%d\n",ans);
	}
}
