#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;
int arr[N];
bool check(int x){
	set<int>p;
	while(x){
		if(p.count(x%10))return 0;
		p.insert(x%10);
		x/=10;
	}
	return 1;
}
signed main(){
	for(int i=0;i<N;i++){
		arr[i] = check(i);
		arr[i] += arr[i-1];
	}
	int t;
	cin >> t;
	while(t--){
		int l,r;
		cin >> l >> r;
		cout << (arr[r] - arr[l-1]) << endl;
	}
}