#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+5;
int arr[N];
int brr[N]; 
int crr[N];
void solve(){
	int n;
	cin >> n;
	int k;
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		arr[i] = k;
		crr[i] = k;
	}
	int ans = min(n,2ll);
	int cnt = 2;
	brr[0] = 0;arr[0] = 5237593759;
	for(int i=1;i<=n;i++){
		brr[i] = arr[i] - arr[i-1];
		if(brr[i] == brr[i-1]){
			cnt++;
			ans = max(ans,cnt);
		}else{
			cnt = 2;
		}
	}
	brr[0] = 1;
	arr[0] = 10100101010;
	cnt = 1;
	for(int i=1;i<=n;i++){
		brr[i] = arr[i]/arr[i-1];
		if(arr[i]%arr[i-1]){
			brr[i] = 0;
			cnt = 1;continue;
		}
		if(brr[i] == brr[i-1]){
			cnt++;
			ans = max(ans,cnt);
		}else{
			cnt = 2;
		}
	}

	for(int i=1;i<=n;i++){
		arr[i] = crr[n+1-i];
	}

	cnt = 2;
	brr[0] = 0;arr[0] = 5237593759;
	for(int i=1;i<=n;i++){
		brr[i] = arr[i] - arr[i-1];
		if(brr[i] == brr[i-1]){
			cnt++;
			ans = max(ans,cnt);
		}else{
			cnt = 2;
		}
	}
	brr[0] = 1;
	arr[0] = 10100101010;
	cnt = 1;
	for(int i=1;i<=n;i++){
		brr[i] = arr[i]/arr[i-1];
		if(arr[i]%arr[i-1]){
			brr[i] = 0;
			cnt = 1;continue;
		}
		if(brr[i] == brr[i-1]){
			cnt++;
			ans = max(ans,cnt);
		}else{
			cnt = 2;
		}
	}
	cout << ans << endl;

	
}
signed main(){
	int t;
	cin >> t;
	while(t--)solve();
}