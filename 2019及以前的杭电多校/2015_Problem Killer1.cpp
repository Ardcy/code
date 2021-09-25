#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int a[N],b[N];
double c[N];
signed main(){
	int n,T;
	cin >> T;
	while(T--){
		cin >> n;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		int ans = min(2,n);
		for(int i=1;i<=n-1;i++){
			b[i] = a[i] - a[i+1];
		}
		int p = 2;
		for(int i=2;i<=n-1;i++){
			if(b[i]==b[i-1]){
				ans = max(ans,++p);
			}else{
				p = 2;
			}
		}
		for(int i=1;i<=n-1;i++){
			c[i] = (double)a[i]/(double)a[i+1];
		}
		p = 2;
		for(int i=2;i<=n-1;i++){
			if(fabs(c[i] - c[i-1]) < 1e-8){
				ans = max(ans,++p);
			}
			else p = 2;
		}
		cout << ans << endl;
	}
}