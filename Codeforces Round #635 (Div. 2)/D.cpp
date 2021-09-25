#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
int a[3];
vector<int>P[3];
int f(int x,int y,int z){
	return (x-y)*(x-y)+(y-z)*(y-z)+(z-x)*(z-x);
}
int ans = 0;
void solve1(){
	int x=0,y=0,z=0;
	for(int i=0;i<P[0].size();i++){
		x=P[0][i];
		//cout<<"solve1 "<<x<<endl;
		if(x==-inf||x==inf)continue;
		y=*lower_bound(P[1].begin(),P[1].end(),x);
		z=*(upper_bound(P[2].begin(),P[2].end(),x)-1);
		if(y==inf||z==-inf)continue;
		if(y==-inf||z==inf)continue;
		//cout<<"solve1 "<<x<<" "<<y<<" "<<z<<endl;
		ans=min(ans,f(x,y,z));
	}	
}
void solve2(){
	int x=0,y=0,z=0;
	for(int i=0;i<P[0].size();i++){
		x=P[0][i];
		if(x==-inf||x==inf)continue;
		y=*lower_bound(P[2].begin(),P[2].end(),x);
		z=*(upper_bound(P[1].begin(),P[1].end(),x)-1);
		if(y==inf||z==-inf)continue;
		if(y==-inf||z==inf)continue;
		ans=min(ans,f(x,y,z));
	}	
}
void solve3(){
	int x=0,y=0,z=0;
	for(int i=0;i<P[1].size();i++){
		x=P[1][i];
		if(x==-inf||x==inf)continue;
		y=*lower_bound(P[2].begin(),P[2].end(),x);
		z=*(upper_bound(P[0].begin(),P[0].end(),x)-1);
		if(y==inf||z==-inf)continue;
		if(y==-inf||z==inf)continue;
		ans=min(ans,f(x,y,z));
	}	
}
void solve4(){
	int x=0,y=0,z=0;
	for(int i=0;i<P[1].size();i++){
		x=P[1][i];
		if(x==-inf||x==inf)continue;
		y=*lower_bound(P[0].begin(),P[0].end(),x);
		z=*(upper_bound(P[2].begin(),P[2].end(),x)-1);
		if(y==inf||z==-inf)continue;
		if(y==-inf||z==inf)continue;
		ans=min(ans,f(x,y,z));
	}	
}
void solve5(){
	int x=0,y=0,z=0;
	for(int i=0;i<P[2].size();i++){
		x=P[2][i];
		if(x==-inf||x==inf)continue;
		y=*lower_bound(P[1].begin(),P[1].end(),x);
		z=*(upper_bound(P[0].begin(),P[0].end(),x)-1);
		if(y==inf||z==-inf)continue;
		if(y==-inf||z==inf)continue;
		ans=min(ans,f(x,y,z));
	}	
}
void solve6(){
	int x=0,y=0,z=0;
	for(int i=0;i<P[2].size();i++){
		x=P[2][i];
		if(x==-inf||x==inf)continue;
		y=*lower_bound(P[0].begin(),P[0].end(),x);
		z=*(upper_bound(P[1].begin(),P[1].end(),x)-1);
		if(y==inf||z==-inf)continue;
		if(y==-inf||z==inf)continue;
		ans=min(ans,f(x,y,z));
	}	
}
signed main(){

	int t;
	cin>>t;
	while(t--){
		int x;
		for(int i=0;i<3;i++)cin>>a[i];
		for(int i=0;i<3;i++){
			P[i].resize(0);
			P[i].pb(-inf);
			P[i].pb(inf);
			for(int j=0;j<a[i];j++){
				cin>>x;
				P[i].pb(x);
			}
			sort(P[i].begin(),P[i].end());
		}
		
		ans = 9e18;
		solve1();
		
		solve2();
		
		solve3();
		
		solve4();
		
		solve5();
		
		solve6();
		cout<<"ans="<<ans<<endl;
		
	}
	return 0;
}


