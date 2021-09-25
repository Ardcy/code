#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans[200];
int a[200];
list<int>l;
signed main(){
	int n;
	cin>>n;
	int d;
	for(int i=1;i<n;i++){
		cin>>a[i]>>d;
		l.push_back(a[i]);
	}
	cin>>a[n]>>a[n+1];
	l.push_back(a[n]);
	l.push_back(a[n+1]);
	int ans=0;
	while(1){
		list<int>::iterator it,u;
		
		int ans1=0;
		int a1,a2,a3;
		for(it=l.begin();it!=l.end();it++){
			if(it==l.begin())continue;
			it++;
			if(it==l.end())continue;
			a1=*it;
			it--;
			a2=*it;
			it--;
			a3=*it;
			it++;
			if(ans1<a1*a2*a3)ans1=a1*a2*a3,u=it;
		}
		ans+=ans1;
		l.erase(u);
		int y=l.size();
		cout<<y<<endl;
		if(y==2)break;
	}
	cout<<ans<<endl;
	return 0;
}
