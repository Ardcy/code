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

int a[2000];
signed main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		vector<int>P,Q;
		for(int i=1; i<=2*n; i++) {
			cin>>a[i];
			if(a[i]%2==1) {
				P.pb(i);
			} else Q.pb(i);
		}
		if(P.size()%2==0) {
			int l = P.size();
			if(P.size()>2) {
				for(int i=0; i<l-3; i+=2) {
					cout<<P[i]<<" "<<P[i+1]<<endl;
				}

				int ll = Q.size();
				for(int i=0; i<ll-1; i+=2) {
					cout<<Q[i]<<" "<<Q[i+1]<<endl;
				}
			} else {
				for(int i=0; i<l-1; i+=2) {
					cout<<P[i]<<" "<<P[i+1]<<endl;
				}

				int ll = Q.size();
				for(int i=0; i<ll-3; i+=2) {
					cout<<Q[i]<<" "<<Q[i+1]<<endl;
				}
			}


			//cout<<l<<" "<<ll<<endl;

		} else {
			int l = P.size();
			for(int i=0; i<l-1; i+=2) {
				cout<<P[i]<<" "<<P[i+1]<<endl;
			}
			int ll = Q.size();
			for(int i=0; i<ll-1; i+=2) {
				cout<<Q[i]<<" "<<Q[i+1]<<endl;
			}
			cout<<l<<" "<<ll<<endl;
		}

	}
	return 0;
}


