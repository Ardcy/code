#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int t;
	cin >> t;
	while(t--){
		int n,x,y;
		cin >> n >> x >> y;
		vector<int>Ans;
		if(n+1<x+y || x*y < n){
			cout <<"NO" << endl;
			continue;
		}
		cout <<"YES" << endl;
		if(y==1){
			for(int i=1;i<n;i++){
				cout << i << " ";
			}cout<< n << endl;
			continue;
		}
		if(x==1){
			for(int i=n;i>1;i--){
				cout << i <<" ";
			}cout << 1 << endl;
			continue;
		}
		int p = ((n - x) + (y-2)) / (y - 1);
		
		stack<int>st;
		int cnt = n;
		for(int i=1;i<p;i++){
			for(int j=y-1;j>=0;j--){
				st.push(cnt - j);
			}
			cnt -= y;
		}
		for(int i=1;i<=x-p;i++){
			Ans.push_back(i);
		}
		for(int i=cnt;i>x-p;i--){
			Ans.push_back(i);
		}
		while(!st.empty()){
			Ans.push_back(st.top());
			st.pop();
		}

		n = Ans.size();
		for(int i=0;i<n-1;i++){
			cout << Ans[i] << " ";
		}
		cout << Ans[n-1] << endl;
		
		
		
	}
}