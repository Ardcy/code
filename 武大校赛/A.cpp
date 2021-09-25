#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair

struct node{
	int x,y;
}a[105000];
bool cmp(node a,node b){
	if(a.x==b.x)return a.y<b.y;
	else return a.x<b.x;
}
bool cmp2(node a,node b){
	if(a.x==b.x)return a.y>b.y;
	return a.x>b.x;
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i].x;
			a[i].y=i;
		}
		a[1].x+=1;
		int op = a[1].x;
		m--;
		int y2 = 0;
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++){
			if(a[i].y==1){
				y2=i;
				i=n+1;
			}
		}
		//cout<<y2<<endl;
		//sort(a+1,a+n+1,cmp);
		int u = 0;
		for(int i=1;i<=n;i++){
			if(a[i].x==op-1)u++;	
		}
		//cout<<u<<endl;
		if(u<=n-1-m){
			cout<<y2<<endl;
		}else{
			cout<<y2+u-(n-1-m)<<endl;
		}
		//sort(a+1,a+n+1,cmp2);
		
	}
	return 0;
}


