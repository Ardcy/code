#include<bits/stdc++.h>
using namespace std;
const int N = 233333;
int arr[N];
double get_p(int x){
	double ans = 0;
	return (x) * log(1.0/365)/log(10);
}
double ans = 0.0;
int sum = 0;


double brr[N];
double C(int n,int m){

	return brr[n] - brr[n-m] - brr[m];
}
signed main(){

	for(int i=1;i<=200000;i++){
		brr[i] = brr[i-1] + log10(i);
	}
	int n;
	cin >> n;
	map<int,int>hp;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
		sum += arr[i];
		hp[arr[i]]++;
	}
	double ans =  C(365,n);
	ans += get_p(sum);

	for(int i=1;i<=n;i++){
		ans +=  C(sum,arr[i]);
		sum -=  arr[i];
	}
	ans += brr[n];
	for(auto p:hp){
		ans -= brr[p.second];
	}
	cout << ans << endl;
	printf("%.10f",ans);
	cout<<endl;
}