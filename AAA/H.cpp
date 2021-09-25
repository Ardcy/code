#include<bits/stdc++.h>
using namespace std;
#define int long long
double boyn=0,girln=0;
double f1 = 0,f2 = 0;
int a[1000500];

signed main(){
	int n,p;
	cin>>n>>p;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	//for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
	int num = 0;
	for(int i=1;i<=n;i++){
		num+=(upper_bound(a+1,a+i,a[i]+p)-lower_bound(a+1,a+i,abs(a[i]-p)))+upper_bound(a+i+1,a+n+1,a[i]+p)-lower_bound(a+i+1,a+n+1,abs(a[i]-p));
	}
	cout<<num/2<<endl;
    return 0;
}
