#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int x,y;
}a[105000];
priority_queue<int,vector<int>,greater<int> >d;
bool cmp(node a,node b){
	return a.x<b.x;
}
signed main(){
	int n,t=0;
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(t<a[i].x){
			t++;
			ans+=a[i].y;
			d.push(a[i].y);
		}
		else if(d.top()<a[i].y){
			ans-=d.top()-a[i].y;
			d.pop(),d.push(a[i].y);
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
