#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int  a[N];
int b[N];
signed main() {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	b[1]=1;
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j>=1; j--) {
			b[j]=b[j-1]-b[j]*a[i];
		}
	}

	for(int j=n; j>1; j--) {
		cout<<b[j]<<" ";
	}
	cout<<b[1]; 
	cout<<endl;



}
