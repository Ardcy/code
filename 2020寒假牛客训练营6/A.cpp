#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<'='<<x<<endl
using namespace std;
#define int long long
#define N 105000

int a[N]={0};
int b[N]={0};
signed main() {
	int n,k;
	cin>>n>>k;
	k=n+1-k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	if(k==n){
		cout<<a[n]+b[n]<<endl;	
	}
	int l=k,r=k;
	debug(k);
	for(int i=k+1;i<=n;i++){
		if(a[k]+b[i]<=a[k+1]+b[i-1]){
			l=i;
		}
	}
	debug(l);
	for(int i=k+1;i<=n;i++){
		if(a[i]+b[l]<=b[l-1]+a[i+1]){
			r=i;
		}
	}
	debug(r);
	cout<<a[l]+b[r]<<endl;
}
