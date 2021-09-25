#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
const int N = 200500;
int qp(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod;
		b>>=1;
	}
	return ans;
};
int inv[N],fac[N],rev[N];
void init(int n) {
	fac[0]=1;
	rev[n]=1;
	for(int i=1; i<=n; i++)fac[i]=fac[i-1]*i%mod;
	rev[n]=qp(fac[n],mod-2);
	for(int i=n-1; i>=0; i--)rev[i]=rev[i+1]*(i+1)%mod;
	for(int i=1; i<n; i++)inv[i]=(rev[i]*fac[i-1]%mod)%mod;
}
int a[1000];
int end1; 
set<int> F;
vector<int>P;
int b[1000];
int end2;
int f = 10;
void Combination1(int m, int n) {
	int i, j;
	for (i = m; i >= n; i--) {
		b[n] = P[i-1];
		if (n > 1) {
			Combination1(i - 1, n - 1);

		} else {
			int sum = 0;
			for (j = 1; j <= end2; j++) {
				//if(f)cout<<b[j]<<" ";
				sum+=b[j];
			}
			//	if(f)cout<<endl;
			f--;
			F.insert(sum);
		}
	}

}
int cnt = 1; 
void Combination(int m, int n) {
	int i, j;

	for (i = m; i >= n; i--) {
		a[n] = i;
		if (n > 1) {
			Combination(i - 1, n - 1);

		} else {
			P.clear();
			for (j = 1; j <= end1; j++) {
				P.pb(a[j]);
			}
			sort(P.begin(),P.end());
			F.clear();
			for(int j=1; j<=end1; j++) {
				end2 = j;
				Combination1(end1,j);
				for(int j1=1; j1<=end1; j1++)b[j]=0;
			}
			//	cout<<F.size()<<endl;
			int l = F.size();
//							for (j = 1; j <= end1; j++) {
//					cout<<P[j-1]<<" ";
//				}
			if(F.size()==31) {
				cout<<"子集和分别为：";
				for(int  p:F)cout<<p<<" ";
				cout<<endl;
				cout<<"case "<<cnt<<":"; 
				for (j = 1; j <= end1; j++) {
					cout<<P[j-1]<<" ";
				}
				cout<<endl;
				cnt++;
			}
		}
	}
}

signed main() {
	int m, n;
	int i;
	cin>>m>>n;
	end1 = n;
	Combination(m, n);// 从m个数中取出n个数的所有组合

	return 0;
}

