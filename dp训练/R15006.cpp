#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n,k;
	string s;
	vector<int>a,b;
	cin>>n>>k;
	cin>>s;
	a.push_back(-1);
	b.push_back(-1);
	for(int i=0;i<n;i++){
		if(s[i]=='a')a.push_back(i);
		else b.push_back(i);
	}
	for(int i=0;i<200000;i++)a.push_back(n),b.push_back(n);
	int ans  = 0;
	for(int i=0;i<110000;i++)ans=max(ans,a[i+k+1]-a[i]-1);
	for(int i=0;i<110000;i++)ans=max(ans,b[i+k+1]-b[i]-1);
	cout<<ans<<endl;
} 
