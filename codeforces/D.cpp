#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
int n;
const int N = 1e5+4;
int a[N];

signed main() {

	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1; i<=n; i++) {
			scanf("%lld",&a[i]);
		}

		int flag = 0;
		int x = 0;
		for(int i = 2; i<n; i++) {
			if(a[i]>a[i-1]&&a[i]>a[i+1]) {
				flag++;
				x = i;
			}
		}
		if(flag==0) {
			cout<<"YES"<<endl;
			continue;
		}
		if(flag == 1 && a[x]<=a[x-1]+a[x+1]) {

			int flag2 = 0;
			for(int i=1; i<x-1; i++) {
				if(a[i]<a[i+1])flag2 = 1;
			}
			for(int i=x+1; i<n; i++) {
				if(a[i]>a[i+1])flag2 = 1;
			}
			if(flag2==0) {
				cout<<"YES"<<endl;
				continue;
			}
		}
		cout<<"NO"<<endl;
	}

}
