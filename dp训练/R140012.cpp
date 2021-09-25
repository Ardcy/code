#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100050];
int sum[105000];

signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	int q;
	int l,r;
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>l>>r;
		cout<<(sum[r]-sum[l-1])/10<<endl;
	}
	return 0;
}
