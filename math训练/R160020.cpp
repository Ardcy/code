#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000],v[1000];
signed main(){
	int n;
	cin>>n;
	set<int>r;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		r.insert(a[i]);
	}
	if(r.size()!=n){
		cout<<-1<<endl;return 0;
	}
	set<int>pr;
	for(int i=1;i<=n;i++){
		int cnt = 1;
		if(v[i])continue;
		v[i]=1;
		int j=i;
		
		while(a[j]!=i){
			cnt++;
			j=a[j];
			v[j]=1;
		}
		if(pr.find(cnt)==pr.end()){
			pr.insert(cnt);
		}
	}
	int ans = 1;
	for(auto p:pr){
		if(p%2==0)p/=2;ans = (ans*p)/(__gcd(ans,p));
	}
	cout<<ans<<endl; 
	return 0;
}
