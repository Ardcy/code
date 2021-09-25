#include<bits/stdc++.h>
using namespace std;
signed main(){
	srand(time(0));
	int n = 1000;
	int m = 10000;
	cout << 1 << endl;
	cout << n << endl;
	for(int i=1;i<=n;i++){
		cout << rand()%m << " " << rand()%m << endl;
	}
}