#include<bits/stdc++.h>
using namespace std;
signed main(){
	int n,m;
	cin >> n >> m;
	cout << ceil((double)pow(sqrt(n)+sqrt(m),6)-(1e-8)) << endl;	
}