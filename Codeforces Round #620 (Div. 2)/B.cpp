#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<'='<<x<<endl
using namespace std;
#define int long long
char d[110][60];
int m;
int a,b;
int y[105],p[105];
int vis[105];
bool huiwen(char e[]){
	for(int i=1;i<=a;i++)
	if(e[i]!=e[a+1-i])return false;
	return true;
}
bool duichen(char e[],char f[]){
	for(int i=1;i<=a;i++)
	if(e[i]!=f[a+1-i])return false;
	return true;
}
signed  main(){
	cin>>b>>a;
	for(int i=1;i<=b;i++){
		cin>>d[i]+1;
	}

	int cnt = 0;
	for(int i=1;i<=b;i++){
		for(int j=i+1;j<=b;j++){
			if(!vis[i]&&duichen(d[i],d[j]))y[cnt++]=i,p[cnt-1]=j,vis[i]=1,vis[j]=1;		
		}
	}
	
	int yy = -1;
	for(int i=1;i<=b;i++){
		if(!vis[i]&&huiwen(d[i])){
			yy=i;
			break;
		}
	}
	int tt = (yy!=-1);
	cout<<(2*cnt)*(a)+a*tt<<endl;
	//cout<<huiwen(d[1])<<endl;
	for(int i=0;i<cnt;i++){
		cout<<d[y[i]]+1;
	}
	if(yy!=-1)cout<<d[yy]+1;

	for(int i=cnt-1;i>=0;i--){
		cout<<d[p[i]]+1;
	}
}
