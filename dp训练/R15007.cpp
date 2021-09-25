#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int f = 0;
		int q1 = m,q2 = m,t = 0;
		int a,b,c;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			q1 = (a-t) + q1;
			q2 = q2 - (a-t);
			if(q1>=b&&q2<=c){
				q1 = min(q1,c);
				q2 = max(q2,b);
				t=a;
			}
			else{
				f = 1;
			}
		}
		if(f==1)cout<<"NO"<<endl;else cout<<"YES"<<endl;
		
	}
	return 0;
}
