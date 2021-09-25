#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000][2];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1];
		}
		int f = 1;
		if(a[1][0]<a[1][1])f=0;
		for(int i=2;i<=n;i++){
			if(a[i][0]<a[i][1])f=0;
			if(a[i][0]<a[i-1][0])f=0;
			if(a[i][1]<a[i-1][1])f=0;
			if(a[i][0]-a[i-1][0]<a[i][1]-a[i-1][1])f=0;
		}
		if(f==1)cout<<"YES"<<endl;else cout<<"NO"<<endl;
	}	
	return 0;
}
