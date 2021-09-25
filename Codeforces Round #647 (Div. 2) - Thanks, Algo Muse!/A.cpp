#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
int qp(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod;
		b>>=1;
	}
	return ans;
};


signed main() {
	int t;
	cin>>t;
	while(t--) {
		int a,b;

		cin>>a>>b;
		if(b>a)swap(a,b);

		int c = a/b;
		if(c*b!=a)cout<<-1<<endl;
		else {
			int ans = 1;
			int f = -1;
			for(int i=1; i<=62; i++) {
				if(c==ans) {
					f=i-1;
					break;
				}
				ans*=2;
			}
			if(f==-1)cout<<f<<endl;
			else
				cout<<(f+2)/3<<endl;
		}
	}
	return 0;
}


