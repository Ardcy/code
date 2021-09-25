#include<bits/stdc++.h>
using namespace std;
signed main(){
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin>> n >> k;
		set<int>st;
		for(int i=k+1;i<=n;i++){
			st.insert(i);
		}
		for(int i=(k+1)/2;i<k;i++){
			st.insert(i);
		}
		cout << st.size() << endl;
		for(auto p:st){
			cout << p << " ";
		}cout << endl;
	}
}