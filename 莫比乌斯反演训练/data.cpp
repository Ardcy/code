#include<bits/stdc++.h>
using namespace std;
signed main(){
	srand(time(0));
	cout << 5000 << endl;
	int n = 5000;
	for(int i=1;i<=n;i++){
		cout << ((rand()<<6)^(rand()))%500000 << " " << ((rand()<<6)^(rand()))%500000 << " " << rand()%20 << endl;
	}
}