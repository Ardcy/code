#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int arr[N];
int sum = 0;
int pre[N];
bool check(int x){
	if(1){
		if(pre[x-1] == (sum - pre[x])){
			return true;
		}else{
			return false;
		}
	}
}
signed main(){
	int n;
	cin >> n;
	
	for(int i=1,k;i<=n;i++){
		cin >> k;
		arr[k] += 1;
		sum += k;
	}
	for(int i=1;i<=20000;i++){
		pre[i] = pre[i-1] + i*arr[i];
	}
	
	for(int i=0;i<=20000;i++){
		if(check(i)){
			cout<<i<<endl;
			return;
		}
	}

}