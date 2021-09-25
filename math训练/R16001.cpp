#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[4000];
signed main(){
	int t;
	cin>>t;
	while(t--){
		
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		int ans = a[1]*a[n];
		int f = 0;
		for(int i=2;i<=sqrt(ans);i++){
			if(i!=sqrt(ans))if(ans%i==0)f+=2;
			if(i==sqrt(ans)&&ans%i==0)f+=1;
		}
		for(int i=1;i<=n;i++){
			if(ans%a[i]!=0)f+=1e7;
		}
		//cout<<f<<endl;
		if(f==n)cout<<a[1]*a[n]<<endl;else cout<<-1<<endl;
		
	}
	return 0;
}
