#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl
#define int long long
struct node{
	int x,y;
}a[300000];
bool cmp(node q1,node q2){return q1.x<q2.x;
}
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		a[i].y=i;
		a[i].x-=i;
	}
	sort(a+1,a+n+1,cmp);
	int ans1 = 0,ans2 = 0;
	ans1 = a[1].x+a[1].y;
	for(int i=1;i<n;i++){
		if(a[i].x==a[i+1].x){
			ans1+=a[i+1].x;
			ans1+=a[i+1].y;
		}
		else{
			ans2=max(ans2,ans1);
			ans1=a[i+1].x;
			ans1+=a[i+1].y;
			ans2=max(ans1,ans2);
		}
	}
	ans2=max(ans1,ans2);
	cout<<ans2<<endl;
	
}
