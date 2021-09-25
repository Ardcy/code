#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int arr[N];
const int mod = 1e9+7;
int qp(int a,int b) {
	int ans = 1;
	while(b) {
		if(b&1) {
			ans *= a,ans%=mod;
		}
		a*=a,a%=mod;
		b>>=1;
	}
	return ans;
}
int d,k;
const double eps = 1e-7;
int a[5000000];
signed main() {
	int n;
	int f1 = 0 , f2 = 0, f3 = 0 , f4 = 0, f5 = 0, f6 = 0;
	cin>>n;
	printf("AND 1 2\n");
	fflush(stdout);
	cin>>f1;

	printf("OR 1 2\n");
	fflush(stdout);
	cin>>f2;

	printf("AND 2 3\n");
	fflush(stdout);
	cin>>f3;

	printf("OR 2 3\n");
	fflush(stdout);
	cin>>f4;

	printf("AND 1 3\n");
	fflush(stdout);
	cin>>f5;

	printf("OR 1 3\n");
	fflush(stdout);
	cin>>f6;

	a[1] = (f1+f2 + f5 + f6 - f3 - f4)/2;
	a[2] = f1 + f2  - a[1];
	a[3] = f5 + f6 - a[1];

	for(int i=4; i<=n; i++) {
		printf("XOR 1 i\n");
		fflush(stdout);
		cin>>f6;
		a[i] = a[1]^f6;
	}
	
	cout<<"! ";
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}cout<<endl;
}
