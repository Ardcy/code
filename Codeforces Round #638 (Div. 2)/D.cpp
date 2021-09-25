#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;}return ans;};

int a[10500];int b[105];
signed main(){
	int t;
	cin>>t;
	a[1]=1;
	b[1]=1;
	for(int i=2;i<33;i++)a[i]=a[i-1]*2;
	for(int i=2;i<33;i++)b[i]=b[i-1]+a[i];
	
	while(t--){
		int n;
		cin>>n;
		vector<int>P;
		//int n1 = upper_bound(a+1,a+12,n)-a;
		while(n){
			int y = upper_bound(b+1,b+33,n)-b;
			int f = max(b[y-1]-b[y-2],n-b[y-1]);
			n-=f;
			P.push_back(f); 
		}
		cout<<P.size()-1<<endl;
		for(int i=P.size()-1;i>=1;i--)cout<<P[i-1]-P[i]<<" ";cout<<endl;
	//	for(auto p:P)cout<<p<<endl;
		
	}
	return 0;
}


