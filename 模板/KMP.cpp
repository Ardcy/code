
#include<bits/stdc++.h>
using namespace std;


vector<int> prefix_function(string s){
	int n = (int)s.length();
	vector<int> pi(n);
	for(int i=1;i<n;i++){
		int j = pi[i-1];
		while(j>0&&s[i]!=s[j])j = pi[j-1];
		if(s[i]==s[j])j++;
		pi[i] = j;
		
	}
	return pi;
}
signed main(){

	vector<int> p = prefix_function("aasca");
	cout << p.size() << endl;
	for(auto i:p){
		cout << i << " ";
	}cout << endl;
}