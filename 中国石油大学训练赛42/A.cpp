#include<bits/stdc++.h>
#define M 100050
#define N 105050
using namespace std;
#define int long long  
struct node{
	int x,y;
	int  dis;
}edge[M<<2];
int fath[N];
int father(int x){
	if(x!=fath[x])fath[x]=father(fath[x]);
	return fath[x]; 
}
void unione(int x,int y){
	fath[father(x)]=father(y);
}
bool cmp(node x,node y){
	return x.dis<y.dis;
}
int n,m;
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)fath[i]=i;

	int cnt = 0;
	for(int j=1;j<=m;j++){
		cnt++;
		cin>>edge[cnt].x;
		cin>>edge[cnt].y;
		cin>>edge[cnt].dis;
	}
	
	sort(edge+1,edge+cnt+1,cmp);
	int ans=0;
	for(int i=1;i<=cnt;i++){
		if(father(edge[i].x)!=father(edge[i].y)){
			unione(edge[i].x,edge[i].y);
			ans+=edge[i].dis;
		}
	}
	cout<<ans<<endl;
	return 0;
}
