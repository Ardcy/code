#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n,x,y,c;
	cin>>n>>y>>x>>c;
	int now=0;
	int i,xr,xl,yu,yd,d;
	x--;
	y--;
	for(i=1;now<c;i++){
		now=i*i+(i-1)*(i-1);
		if(now<c)continue;
		i--;
		xr=x+i;
		xl=x-i;
		yu=y-i;
		yd=y+i;
		if(xl<0)now-=xl*xl;
		if(xr>n-1)now-=(xr-n+1)*(xr-n+1);
		if(yu<0){
			now-=yu*yu;
			yu++;
			d-=yu;
			if(x+d>n-1)now+=(x+d-n+2)*(x+d-n+1)/2;
			if(x+yu<0)now+=(x-d)*(x-d-1)/2;
		}
		if(yd>n-1){
			now-=(yd-n+1)*(yd-n+1);
			d=yd-n+1;
			d--;
			if(x+d>n-1)now+=(x+d-n+2)*(x+d-n+1)/2;
			if(x-d<0)now+=(x-d)*(x-d-1)/2;
		}
		i++;
	}
	cout<<i-2<<endl;
	return 0;
}

