#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair

int a[205000];
int b[205000];
int c[205000];
signed main(){
	
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[i]=0;c[i]=0;
		}
		for(int i=2;i<n;i++){
			if(a[i]>a[i-1]&&a[i]>a[i+1]){
				b[i]=1;
			}else{
				b[i]=0;
			}
			//c[i]=c[i-1]+b[i];
		}
		for(int i=2;i<=n;i++)c[i]=c[i-1]+b[i];
		int ans = 0,ansl = 1;
		for(int i=1;i<=n-k+1;i++){
			if(c[i+k-2]-c[i]>ans){
				ans=c[i+k-2]-c[i];
				ansl=i;
			}
		}
		cout<<ans+1<<" "<<ansl<<endl;
	}
	return 0;
}


