#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n;
	int sum=0,a;
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a;
		sum+=(a-90);
	}
	printf("%.2f%\n",(sum*100.0)/(9*n+sum));
}
