#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+500;
int a[N];
int n,t,sum=0;
signed main() {
  	cin>>n;
  	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>t;
		a[i]=(a[i-1]^t);
	}
	sort(a,a+n+1);
	for(int i=0;i<=n;i++){
		int k = 1;
		while(a[i+1]==a[i]&&i+1<=n){
			k++;
			i++;
		}
		sum+=(k-1)*k/2;
	}
	cout<<sum<<endl;
}
