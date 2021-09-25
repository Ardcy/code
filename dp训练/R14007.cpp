#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int q;
	string s,t;
	cin>>q;
	while(q--){
		int n;
		cin>>n;
		cin>>s>>t;
		int u=0;
		int flag=0;
		for(int i=0;i<n;i++){
			if(u==0)if(s[i]<'3'){
				u=0;continue;
			}else {
				if(t[i]<'3')flag=1;
				u=1;continue;
			}
			if(u==1)if(t[i]<'3'){
				u=1;continue;
			}else{
				if(s[i]<'3')flag=1;
				u=0;continue;
			}
		}
		if(flag==1)cout<<"NO"<<endl;
		else if(u==1)cout<<"YES"<<endl;else cout<<"NO"<<endl;
	}
	
	
}
