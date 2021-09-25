#include<bits/stdc++.h>
using namespace std;
#define int long long
double a[2000];
double b[2000];
double c[2000];
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(i!=j){
				c[cnt++]=(a[j]-a[i])*(a[j]-a[i])+(b[j]-b[i])*(b[j]-b[i]);			
			}
		}
		int e=0;
		for(int j=1;j<=cnt;j++){
			if(abs(c[j]-c[j-1])<1e-6)e++;
		}
		if(e==cnt-1)cout<<i<<endl;
	}
	return 0;
}
