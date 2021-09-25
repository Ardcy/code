#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int arr[N+5];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		n = abs(n), m = abs(m);
		if(n==m)
		cout<<( min(n,m)*2)+(max(n,m)-min(n,m))*2<<endl;
		else{
			cout<<( min(n,m)*2)+(max(n,m)-min(n,m))*2-1<<endl;
		}
	}
	
	return 0;
}
