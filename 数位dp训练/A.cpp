#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 50;
int arr[N];
int ans;

void dfs(int x,bool limit){

	
}
int get_ans(int n){
	int cnt = 0;
	while(n){
		arr[cnt++] = n%10;
		n/=10;
	}
	ans = 0;
	dfs(cnt-1,1);
	return ans;
}
signed main(){
	int t;
	cin >> t;
	while(t--){
		int l,r;
		cin >> l >> r;
		cout <<(get_ans(r) - get_ans(l-1))<<endl;
	}
}