#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int n;
unordered_map<string,int>P;

int main(){
	std::ios::sync_with_stdio(false);
	cin>>n;
	string s;
	
	for(int i=1;i<=n;i++){
		cin>>s;
		P[s]++;
	}
	int ans = 0;
	for(unordered_map<string, int>::iterator it=P.begin();it!=P.end();it++){
		ans=max(it->second,ans);
	}
	for(unordered_map<string, int>::iterator it=P.begin();it!=P.end();it++){
		if(it->second==ans){
		s=it->first;		
		for(int j=0;j<s.length();j++){
			printf("%c",s[j]);
		}
		printf("\n");
		}
	}
	return  0;
}
