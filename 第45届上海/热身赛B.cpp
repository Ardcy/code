#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
double arr[N];
double brr[N];
const double pi = acos(-1.0);
signed main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	sort(arr+1,arr+n+1);
	for(int i=1;i<=n;i++){
		arr[i] -= 360.0/n * i;
		brr[i] = arr[i];
	}
	sort(brr+1,brr+n+1);
	double ans = 0.0;
	if(n&1){
		for(int i=1;i<=n;i++){
			ans += abs(brr[n/2+1] - brr[i])/360 * pi;
		}
		printf("%.10f\n",2*ans);
	}
	else{
		double ans1=0.0;
		for(int i=1;i<=n;i++){
			ans += abs(brr[n/2+1] - brr[i])/360 * pi;
		}
		for(int i=1;i<=n;i++){
			ans1 += abs(brr[n/2] - brr[i])/360 * pi;
		}
		printf("%.10f\n",2*min(ans1,ans));
	}
}