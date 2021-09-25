#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
#define int long long
int f[10500];
void ini(int n) {
	for (int i = 1; i <= n; i++)
		f[i] = i;
}
int find(int x) {
	return f[x] == x ? x : (f[x] = find(f[x]));
}
void merge(int i, int j) {
	f[find(i)] = find(j);
}
bool query(int i, int j) {
	return find(i) != find(j);
}
int b[10000];
signed main() {
	int t,n,m;
	int a,c;
	int cnt;
	cin>>t;
	while(t--){
		cnt=0;
		cin>>n>>m;
		for (int i = 1; i <= n; i++)f[i] = i;
		for(int i=1;i<=m;i++){
			cin>>a>>c;
			if(query(a,c))merge(a,c);
		}
		for(int i=1;i<=n;i++)if(find(i)==i)cnt++;
		cout<<cnt<<endl;
	} 
	return 0;
}

