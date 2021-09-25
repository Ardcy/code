#include<bits/stdc++.h>
using namespace std; 
const int N = 2e6+5;

int a[N];
signed main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		long long sum = 0;
		for(int i=1;i<=m;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+m+1);
		sum+=(k-1);
		for(int i=m;i>1;i--){
			sum+=2*abs(k-a[i]);
		}
		sum+=abs(a[1]-k)+a[1]-1;
		printf("%lld\n",sum);
	}
	return 0;
}


