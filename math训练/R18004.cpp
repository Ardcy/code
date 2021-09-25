#include<bits/stdc++.h>
using namespace std;
long double b[105000];
long double pi = acos(-1.0);
signed main(){
	int n;
	cin>>n;
	ios::sync_with_stdio(false);
	long double x,y;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		b[i]=atan2(x,y);
		b[i]=b[i]/pi*180;
		if(b[i]<0)b[i]+=360;
	}
	sort(b+1,b+n+1);
	long double temp = b[1]-b[n]+360;
	for(int i=1;i<=n-1;i++){
		temp=max(temp,b[i+1]-b[i]);
	}
	//printf("%.10Lf\n",360-temp);
	cout<<fixed<<setprecision(10)<<(360-temp)<<endl; 
	return 0;
}
