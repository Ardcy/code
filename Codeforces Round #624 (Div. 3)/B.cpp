#include<bits/stdc++.h>
using namespace std;
#define int long long
#define de(x) cerr<<#x<<"="<<x<<endl
void solve(){
	
}
int a[200];
int p[200];
int b[200];
signed main(){
	int t,m,n;
	cin>>t;
	int l,r;
	while(t--){
		memset(b,0,sizeof(b));
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=m;i++)cin>>p[i],b[p[i]]=1;
		for(int i=1;i<=n;i++){
			if(b[i]==1){
				l=i;
				while(b[i+1]==1)i++;
				r=i+1;
				//de(l);
				//de(r);
				sort(a+l,a+r+1);
			}
		}
		int f=1;
		for(int i=2;i<=n;i++){
			if(a[i]<a[i-1])f=0;
		} 
		if(f==1)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}	
} 
