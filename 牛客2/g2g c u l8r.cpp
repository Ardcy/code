#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n;
	cin >> n;
	map<string,string>mp;
	for(int i=1;i<=n;i++){
		string tem;
		cin>>tem;
		getchar();
		string p;
		getline(cin,p);
		mp[tem] = p;
	}

	int m;
	cin >> m;getchar();
	for(int i=1;i<=m;i++){
		string p;
		getline(cin,p);
		string tem="";
		for(int i=0;i<p.length();i++){

			if(p[i]==' '||i==p.length()-1){
				if(i==p.length()-1)tem+=p[i];
				if(tem.length()){
					if(mp.count(tem)){
						cout << mp[tem] <<" ";
					}else{
						cout << tem << " ";
					}
				}
				tem = "";
				
			}else tem += p[i];
		}
		cout << endl;
		
	}
}