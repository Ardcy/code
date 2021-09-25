#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
pair<int,int> s[205000]; 
int main(){
	int n;
	cin>>n;
	int l=INT_MIN;
	int r=INT_MAX;
	for(int i=1;i<=n;i++){
		cin>>s[i].fi>>s[i].se;
	}
	int pre = 0;
	for(int i=1;i<=n;i++){
		if(s[i].se==1)l=max(l,1900-pre);
		else r=min(r,1899-pre);
		pre+=s[i].first;
	}
	if(l>r)cout<<"Impossible"<<endl;
	else if(l<=r&&r==INT_MAX)cout<<"Infinity"<<endl;
	else cout<<r+pre<<endl;
}
