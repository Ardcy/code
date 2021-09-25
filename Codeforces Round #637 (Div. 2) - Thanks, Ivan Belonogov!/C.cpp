#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
int a[105000];
signed main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		for(int i=1; i<=n; i++)cin>>a[i];
		int f = 1;
		int y = n;
		int aa = a[1],bb=a[1];
		for(int i=2; i<=n; i++) {
			if(a[i]==a[i-1]+1) {
				bb++;
			} else {
				if(bb!=y) {
					f=0;
					break;
				} else {
					if(a[i]>=aa) {
						f=0;
						break;
					} else {
						y=aa-1;
						aa=a[i];
						bb=a[i];
					}
				}
			}
		}
		if(f)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}


