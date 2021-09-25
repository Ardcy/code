#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int e[100]; 
struct node{
	int x,y;
}d[60000];
bool cmp(node a,node b){
	if(a.x==b.x)return a.y<b.y;
	return a.x>=b.x;
}
bool cmp1(node a,node b){
	if(a.x==b.x)return a.y<b.y;
	return a.x<b.x;
}
signed main(){
	cin>>n>>k;
	for(int i=1;i<=10;i++)cin>>e[i];
	for(int i=1;i<=n;i++)cin>>d[i].x,d[i].y=i;
	sort(d+1,d+n+1,cmp1);
	for(int i=1;i<=n;i++){
		d[i].x+=e[(i-1)%10+1];	
	}
	sort(d+1,d+n+1,cmp);
	for(int i=1;i<k;i++){
		cout<<d[i].y<<" ";
	}
	cout<<endl;
	return 0;
}

