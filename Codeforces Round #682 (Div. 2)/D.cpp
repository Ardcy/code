#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int a[N+5];
signed main(){
	int t;
	t = 1;
	while(t--){
		int n;
		cin>>n;
		int ans = 0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			ans^=a[i];
		}
		if(n&1){
			cout<<"YES"<<endl;
			cout<<(n-1)<<endl;
			for(int i=1;i<=n/2;i++){
				printf("%lld %lld %lld\n",2*i-1,2*i,n);
			}
			for(int i=1;i<=n/2;i++){
				printf("%lld %lld %lld\n",2*i-1,2*i,n);
			}
		}
		else if(ans==0){
			cout<<"YES"<<endl;
			n-=1;
			cout<<(n-1)<<endl;
			for(int i=1;i<=n/2;i++){
				printf("%lld %lld %lld\n",2*i-1,2*i,n);
			}
			for(int i=1;i<=n/2;i++){
				printf("%lld %lld %lld\n",2*i-1,2*i,n);
			}
		}else{
			cout<<"NO"<<endl;
		}
		
	}
	
	return 0;
}
