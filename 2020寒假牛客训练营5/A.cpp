#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b; 
signed main() {
	int n,m;
	cin>>n>>m;
	cin>>a>>b;
	int cnt = 0;
	for(int i=0;i<min(n,m);i++){
		if(a[i]!=b[i])cnt++;
	}
	cnt+=(max(n,m)-min(n,m));
	cout<<cnt<<endl;
}
