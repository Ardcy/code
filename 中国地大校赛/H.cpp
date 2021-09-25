#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;}return ans;};

double a[1000][2];
struct node{
	double x,y;
}e[1000];
bool cmp(node a1,node a2){
	return a1.x<a2.x;
}
bool cmp1(node a1,node a2){
	return a1.y<a2.y;
}

signed main(){
	int t;
	t=1;
	while(t--){
		int n,x,y;
		cin>>n>>x>>y;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1];
			e[i].x=a[i][0];
			e[i].y=a[i][1];
		}
		sort(e+1,e+n+1,cmp);
		double ans1 = x;
		double ans2 = 0;
		sort(e+1,e+n+1,cmp1);
		ans1 = max(e[1].x,x-e[n].x);
		ans2 = max(e[1].y,x-e[n].y);
		
		
		
		double ans11 = y;
		double ans21 = 0;
		for(int i=1;i<=n;i++){
			ans11 = min(ans11,a[i][1]);
			ans21 = max(ans21,a[i][1]);
		} 
		
		double ans01 = max(y-ans21,ans11);
		double u1;
		for(int i=1;i<n;i++){
			double ans31 = 1e9;
			for(int j=i+1;j<=n;j++){
				u1 = sqrt((e[i].x-e[j].x)*(e[i].x-e[j].x)+(e[i].y-e[j].y)*(e[i].y-e[j].y));
				ans31=min(ans31,u1);
			}
			ans01 = max(ans01,ans31);
		}
		cout<<ans0<<" "<<ans01<<endl;
		cout<<min(ans0,ans01)<<endl;
	}
	return 0;
}


