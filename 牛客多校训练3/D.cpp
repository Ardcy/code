#include<bits/stdc++.h>
using namespace std;
int arr[2000];
signed main(){
	int n;
	cin >> n;
	int m=0;
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		arr[k] = 1;
		m = max(k,m);
	}
	for(int i=1;i<=n;i++){
		if(!arr[i]){
			cout << i << endl;
		}
	}
}