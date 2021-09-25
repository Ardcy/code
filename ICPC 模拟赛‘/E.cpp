#include <iostream>
#define int long long
using namespace std;
int a[150];	
int n;

int get_max(){
	int MAX = 0, res, pre = a[1];
	for(int i = 2; i <= n -1 ; i++) {
		if(a[i] > MAX) {
			res = i;
			MAX = a[i];
			int j = i + 1;
			int temp_res = i;
			while(j <= n - 1 && (a[j] == MAX || a[j] == -1)) {
				if(a[j] == MAX) temp_res = j;
				j++;
			}
			i = j - 1;
			// cout << i << " " << j << endl;
			if(a[j] < pre) {
				res = temp_res;
			}
		}
		if(a[i] != -1) pre = a[i];
	}
	return res;
}
int get_value(int idx) {
	int l = idx - 1,  r = idx + 1;
	while(a[l] == -1) l--;
	while(a[r] == -1) r++;
	return a[idx] + a[r] + a[l];
}
signed main() {

	while(cin >> n) {
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int ans = 0;
		for(int i = 1; i <= n - 2; i++) {
			int idx = get_max();
			int value = get_value(idx);
			ans += value * value;
			// cout << idx << " " << value << endl;
			a[idx] = -1;
		}
		cout << ans << endl;
		
	} 
	return 0;
}
