#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
const int N = 200500;

double a[N]= {0};
int main() {
	int k;
	cin>>k;
	for(int i=0;i<N;i++)a[i]=-200;
	
	for(int i=1; i<=k; i++) {
		int u;
		double v;
		cin>>u>>v;
		a[u]=0;
		a[u]+=v;
	}
	
	cin>>k;
	for(int i=1; i<=k; i++) {
		int u;
		double v;
		cin>>u>>v;
		if(abs(a[u]+200)<1e-5)a[u]=0;
		a[u]+=v;
	}
	
	int cnt=0;
	for(int i=0; i<N; i++) {
		if(a[i]>0.0)cnt++;
	}
	cout<<cnt;
	for(int i=N-1; i>=0; i--) {
		if(a[i]>0.0) {
			cout<<" ";cout<<i;
			
			cout<<" ";printf("%.1f",a[i]);
		}
	}
	return 0;
}


