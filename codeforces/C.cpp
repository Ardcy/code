#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
int n;
struct node {
	int x,y;
	bool operator < (const node & p)const {
		return x < p.x;
	}
} e[205000];

signed main() {

	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1; i<=n; i++) {
			scanf("%lld",&e[i].x);
		}
		for(int i=1; i<=n; i++) {
			scanf("%lld",&e[i].y);
		}
		sort(e+1,e+n+1);

		int ans = e[n].x;

		int pre = 0;
		for(int i=n-1;i>=0; i--) {
			pre += e[i+1].y;
			ans = min(ans,max(e[i].x,pre));
		}
		cout<<ans<<endl;
	}

}
