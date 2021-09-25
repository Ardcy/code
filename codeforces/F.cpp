#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
int n,k;
const int N = 2e5+4;
int a[N];
int b[N];
int c[N]; 
set<int>P;
const int mod = 998244353;
signed main() {

	cin>>T;
	while(T--) {
		P.clear();
		cin>>n>>k;
		for(int i=1; i<=n; i++) {
			scanf("%lld",&a[i]);
			c[a[i]]=i;
		}
		for(int i=1;i<=k;i++){
			scanf("%lld",&b[i]);
			P.insert(b[i]);
		}
		int ans = 1;
		for(int i=1;i<=k;i++){
			int vis = c[b[i]];
			
			if(vis==1){
				if(P.count(a[2])){
					ans*=0;
				}
				P.erase(a[1]);
			}else if(vis==n){
				if(P.count(a[n-1])){
					ans*=0;
				}
				P.erase(a[n]);
			}else{
				int cnt = 2;
				cnt -= P.count(a[vis+1]) + P.count(a[vis-1]);
				ans*=cnt;
				
				if(!P.count(a[vis+1])){
					P.erase(a[vis]);
				}else{
					P.erase(a[vis]);
				}
			}
			ans%=mod;
		}
		cout<<ans<<endl;
		

	}

}
