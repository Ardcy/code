#include<bits/stdc++.h>
using namespace std;
#define int long long
int arr[200000];
signed main(){
	int n,m,x,base=0,tp;
	cin >> n >> m >> x;
	priority_queue<int,vector<int>,greater<int> >pq;
	int u;
	for(int i=1;i<=m;i++){
		cin >> u;
		pq.push((u+x-1)/x);
		if( (u+x-1)/x > base ) base =  (u+x-1)/x;
	}
	for(int i=m+1;i<=n;i++){
		int tp = pq.top();pq.pop();
		cin >> u;
		pq.push(tp+(u+x-1)/x);	
		if(tp + (u+x-1)/x > base) base = tp + (u+x-1)/x;
	}
	cout << base << endl;
}