#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105000];
int b[105000];
int c[105000];
signed main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]>0)b[i]+=1;
		b[i]+=b[i-1];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0)c[i]+=1;
		c[i]+=c[i-1];
	}
	int ans = 105000;
	for(int i=1;i<n;i++){
		ans = min(ans,b[i]+(n-i)-(b[n]-b[i])+c[i]); 
	}
	cout<<ans<<endl;
	return 0;
}
