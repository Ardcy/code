#include<bits/stdc++.h>
using namespace std;
signed main(){
	string s;
	cin >> s;
	int cnt = 0;
	int n = s.length();
	for(int i=0;i<n-2;i++){
		if(s.substr(i,3)=="cat"||s.substr(i,3)=="dog"){
			cnt++;
		}
	}
	cout << cnt<<endl;
}