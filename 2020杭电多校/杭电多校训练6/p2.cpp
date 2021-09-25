#include<bits/stdc++.h>
using namespace std;
const int N = 3e6;
stru arr[N];

signed main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	random_shuffle(arr+1,arr+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int z = j+1;z<=n;z++){
				for(int f = z+1;f<=n;z++){
					if(arr[i]+arr[j] == arr[z] + arr[f]){
						cout << 
					}
				}
			}
		}
	}
}