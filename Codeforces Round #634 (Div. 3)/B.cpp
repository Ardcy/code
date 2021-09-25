#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair

signed main(){
	int t;
	cin>>t;
	while(t--){
		int n,b,a;
		cin>>n>>a>>b;
		for(int i=0;i<n;i++){
			cout<<(char)('a'+i%b);
		}
		cout<<endl;
	}
	return 0;
}


