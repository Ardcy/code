#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define endl (" ")
int a[60];
signed main(){
	int t;
	a[0]=1;
	for(int i=1;i<=31;i++){
		a[i]=a[i-1]*4;	
	}
	//cout<<a[31]<<endl;
	cin>>t;
	int n=0;
	while(t--){
		cin>>n;
		//n++;
		int y = lower_bound(a,a+30,n)-a;
		if(a[y]>n)y--;
		int d = n-a[y];
		int b = d%3;
		if(b==0){
			cout<<a[y]+d/3<<endl;
		}
		else if(b==1){
			int b1=d/3;
			int ans2=0;
			int d3=1;
			while(b1){
			int r = b1%4;
			int r1 = b1-r,r2=0;
			if(r==0)r2=0;
			else if(r==1)r2=2;
			else if(r==2)r2=3;
			else if(r==3)r2=1;
			ans2+=r2*d3;
			b1>>=2;
			d3*=4;
			}

			cout<<(a[y]*2+ans2)<<endl;
		}
		else if(b==2){
			int b1=d/3;
			int ans2=0;
			int d3=1;
			while(b1){
			int r = b1%4;
			int r1 = b1-r,r2=0;
			if(r==0)r2=0;
			else if(r==1)r2=3;
			else if(r==2)r2=1;
			else if(r==3)r2=2;
			ans2+=r2*d3;
			b1>>=2;
			d3*=4;
			}
			cout<<(a[y]*3+ans2)<<endl;
		}
	}
	return 0;
}


