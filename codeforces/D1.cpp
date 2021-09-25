#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
int n;
const int N = 1e5+4;
int a[N];
int b[N]; 
signed main() {

	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1; i<=n; i++) {
			scanf("%lld",&a[i]);
		}
		a[n+1] = 100000005;
		int x = 0;
		for(int i=1;i<=n;i++){
			if(a[i]>=a[i+1]){
				b[i] = 0;
			}
			else{
				x = i;
				b[i] = 0;
				a[i+1] = a[i+1] - a[i];
				int p = a[i];
				//cout<<p<<endl;
				for(int i = x + 1; i<n; i++){
					if(a[i+1] < a[i] ){
						break;
					}
					else{
						int u = a[i+1];
						a[i+1] = max(a[i],a[i+1]-p);
						p = u - a[i+1];
						//cout<< i << " " << a[i+1]<<endl;
					}
				}
				break;
			}
		}
	//	for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
		for(int i=1;i<=x;i++)a[i]=b[i];
	//	for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
		int flag = 0;
		int y = n;
		for(int i=n;i>=x;i--){
			if(a[i]>=a[i-1]){
				b[i] = 0;
			}
			else{
				flag = 1;
			}
		}
		if(flag){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
		}

	}

}
