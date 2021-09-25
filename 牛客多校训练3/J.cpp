#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+5;

long long int arr[N];


signed main(){
	int n;
	cin >> n;
	long long sum = 0;
	double ans=0.0;
	for(int i=1;i<=n;i++){
		int k;
		cin >> arr[i];
		k = arr[i];
		sum += k;
		ans = max(ans,sum*1.0/i);
		//cout << sum*1.0/i << " ";
	}//cout << endl;
	double ans1 =0;
	sum = 0;
	for(int i=n;i>=1;i--){
		sum += arr[i];
		//cout << sum*1.0/(n+1-i) << " ";
		ans1 = max(ans1,sum*1.0/(n+1-i));
	}//cout << endl;
	// cout << max(ans,ans1) << endl;
	printf("%.10f\n",max(ans,ans1));

}