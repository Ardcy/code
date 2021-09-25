#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int N = 1e7+5;
int f[N],arr[N],brr[N],crr[N];
signed main(){
	f[1] = 1;f[2] = 2;
	for(int i=3;i<N;i++){
		f[i] = f[i-1] + f[i-2];
	}
	int t;
	scanf("%llu",&t);
	while(t--){
		int n;
		int a=0,b=0,c=0;
		
		scanf("%llu",&n);
		int k;
		for(int i=1;i<=n;i++){
			scanf("%llu",&k);
			a += k*f[i];
		}
		scanf("%llu",&n);
		for(int i=1;i<=n;i++){
			scanf("%llu",&k);
			b += k*f[i];
		}
		scanf("%llu",&n);
		for(int i=1;i<=n;i++){
			scanf("%llu",&k);
			c += k*f[i];
		}
		int d = a*b;
		for(int i=1;i<n;i++){
			if(c + f[i] == d){
				printf("%llu\n",i);
				break;
			}
		}
	}
}