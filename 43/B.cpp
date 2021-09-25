#include<bits/stdc++.h>
using namespace std;
int a[200];
int main() {
	int n; 
	cin >> n; 
	int f = 0;
	for (int j = 0; j <= n / 4; j++) {
		for (int k = 0; k <= n / 7; k++) {
			if (4 * j + 7 * k == n) f = 1;
		}
	}
	if (f==0) cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}
