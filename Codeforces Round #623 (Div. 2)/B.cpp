#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl
#define int long long
map<char,int>mp;
signed main(){
	int t,a,b,p;
	cin>>t; 
	while(t--){
		cin>>a>>b>>p;
		string s;
		string q="C";
		cin>>s;
		int ans = 0;
		for(int i=s.length()-1;i>=0;i--){
			q+=s[i];
		}
		ans = 0;
		mp['A']=a;
		mp['B']=b;
		if(q[1]!=q[2]&&mp[q[2]]>p){
			cout<<q.length()-1<<endl;
			continue;
		}
		if(q[1]==q[2]&&mp[q[1]]>p){
			cout<<q.length()-1<<endl;
			continue;
		}		
		int ff=1;
        for(int i=1;i<q.length()-1;i++)if(q[i]!=q[i+1])ff=0;
		if(ff==1&&mp[q[1]]<=p){
			cout<<1<<endl;
			continue;
		}
		int tt=1;
		if(q[1]==q[2])ans+=mp[q[1]];
		else ans+=mp[q[2]];
		for(int i=2;i<=q.length()-1;i++){
			if(q[i]!=q[i+1]){
				ans+=mp[q[i+1]];
				if(ans>p){
					cout<<q.length()-i<<endl;
					tt=0;
					break;	
				}
			}
		}
		if(tt)cout<<1<<endl;
	}
	
}
