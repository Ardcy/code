#include<bits/stdc++.h>
using namespace std;
signed main(){
	srand(time(0));
	int n = 500;
	cout << n << endl;
	for(int i=1;i<=n;i++){
		cout << (rand()%300) + 1<< " ";
	}	cout << endl;
}