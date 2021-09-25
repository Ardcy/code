#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int a[N];
signed main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	for(int i=0;i<s.length();i++){
		a[i] = (s[i]=='A');
	}
	int cnt = 0;
	for(int i=s.length();~i;i--){
		if((a[i]+cnt)%2 == 0){
			cnt++;
		}
	}
	cout << cnt <<endl;
}