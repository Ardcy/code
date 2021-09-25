#include<bits/stdc++.h>
using namespace std;
set<int>P;
signed main(){
    int u;
    while(cin>>u){
    	//cin>>u;
		P.insert(u);
    	
	}
	    
    
    vector<int>t;
    for(auto p:P)t.push_back(p);
    sort(t.begin(),t.end());
    for(int i=0;i<t.size();i++){
	    cout<<t[i]<<" ";
		cout<<t[i]<<" ";
		cout<<t[i]<<" ";
    }cout<<endl;
}
