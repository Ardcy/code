#include<bits/stdc++.h>
using namespace std;
#define int long long
map<string,string>P;
map<string,int>T;
int coun = 0;
void dfs(int a,int n,string s){
	if(a>n)return;
	if(a==n){
		T[s]++;
		//cout<<coun<<" "<<s<<endl;
		coun = coun+1;
		return;
	}
	string u,k;
	for(int i=0;i<1;i++){
		u=s.substr(i,1);
		for(auto it=P.begin();it!=P.end();it++){
			if(it->second==u){
				if(i==0)k=it->first+s.substr(1,a-1);
				else if(i==a)k=	s.substr(0,a-1)+it->first;
				else {
					k=s.substr(0,i)+it->first+s.substr(i+1,a-i-1);
				}
				dfs(k.length(),n,k);
			}
		}
		
	}
	
}
signed main(){
	int n,q;
	cin>>n>>q;
	string s;
	string t;
	for(int i=1;i<=q;i++){
		cin>>s>>t;
		P[s]=t;
	}
	dfs(1,n,"a");
	cout<<T.size()<<endl;
	return 0;
} 
