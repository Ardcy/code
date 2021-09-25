#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[20];
signed main() {
 	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
  		cin>>a[i];
	}
	int p = a[9];
	sort(a+1,a+n+1);
	int k = a[n-2];
	if(p>=k||p>=m*0.8){
		puts("Yes");
	}
	else puts("No");
}
