#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int a[N+5];
signed main(){
	int t;
	cin>>t;
	while(t--){
		set<int>P;
		int n;
		cin>>n;
		int flag = 0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(P.count(a[i]))flag = 1;
			P.insert(a[i]);
		}
		if(flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
	
	return 0;
}
