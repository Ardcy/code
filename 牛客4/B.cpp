#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int arr[N];
int brr[N];
signed main(){
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	
	sort(arr+1,arr+n+1);
	for(int i=1;i<=m;i++){
		cin >> brr[i];
	}
	sort(brr+1,brr+1+m);
	int cnt = 0;
	int num = 1;
	for(int i=1;i<=n;i++){
		if(arr[i] >= brr[num]){
			cnt++;
			num++;
		}
	}
	cout << cnt << endl;
}