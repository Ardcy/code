#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3005;
int a[N];
int pre[N][N];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		set<int>P;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			P.insert(a[i]);
		}
		for(auto p:P){
			for(int i=1;i<=n;i++){
				if(a[i]==p)pre[p][i]=pre[p][i-1]+1;
				else pre[p][i]=pre[p][i-1];
			}
		}
		int ans = 0;
		for(int i=2;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				ans+=pre[a[j]][i-1]*(pre[a[i]][n]-pre[a[i]][j]);	
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


