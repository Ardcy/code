#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[206000];
vector<int>B[205000];
int r[205000];
signed main(){
	int n,m,cnt = 0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(B[cnt].size()==m)cnt++;
		B[cnt].push_back(a[i]);
	}
	cnt = 0;
	int pos = 0;
	int ans = 0;
	for(int i=1;i<=n;i++){
		r[pos]+=B[cnt][pos];
		ans+=r[pos];
		pos++;
		if(pos==m)cnt++,pos=0;
		cout<<ans;
		if(i<n)cout<<" ";
	}
	return 0;
}
