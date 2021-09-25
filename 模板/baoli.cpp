#include<bits/stdc++.h>
using namespace std;
int arr[100000];
signed main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int w = j+1;w<=n;w++){
				if(arr[i]+arr[w]==arr[j]*2){
					ans +=1;
				}
			}
		}
	}
	cout << ans << endl;
}