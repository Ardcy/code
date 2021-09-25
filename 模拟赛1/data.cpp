#include<bits/stdc++.h>
using namespace std;
int arr[3000];
signed main(){
	srand(time(0));
	int n = 10;
	cout << n << endl;
	int k = 4;
	cout << k << endl;
	while(1){
		set<int>P;

		for(int i=1;i<=n;i++){
			arr[i] = rand()%k + 1;
			P.insert(arr[i]);
		}	
		if(P.size() == k){
			for(int i=1;i<=n;i++){
				cout << arr[i] << " ";
			}cout<<endl;
			break;
		}
	}
	
}