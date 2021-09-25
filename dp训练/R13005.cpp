#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[200];
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++)cin>>a[i];
		int ans=0;
		for(int i=1;i<n;i++){
			int top = a[i+1]+k;
			int bot = max(a[i+1]-k,0);
			m+=(a[i]-bot);
			if(m<0)ans=1;
		}
		if(ans)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}
