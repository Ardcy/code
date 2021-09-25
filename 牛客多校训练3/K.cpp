#include<bits/stdc++.h>
using namespace std;

signed main(){
	string s;
	cin >> s;
	set<char>p;
	for(auto q:s){
		p.insert(q);
	}
	long long int ans = 0;
	set<char>y;
	for(auto q:s){
		if(y.count(q)==0){
			ans += p.size() - y.size() - 1;
		}
		y.insert(q);
	}
	cout << ans << endl;
}