#include<bits/stdc++.h>
using namespace std;
signed main() {
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int a[6] = {1,2,3,4,5,6};
	int b[6] = {1,4,2,5,3,6};
	int cnt = 0;
	do {
		cnt++;
		int flag = 1;

		for(int i=0; i<6; i++) {
			if(a[i]!=b[i])flag = 0;
		}
		if(flag)cout<<cnt<<endl;
		if(flag) {
			for(int i=0; i<=5; i++) {
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}

	} while(next_permutation(a,a+6));
}
