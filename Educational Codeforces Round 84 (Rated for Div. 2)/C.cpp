#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define int long long
typedef vector<int> VI;
typedef pair<int,int> PII;
const int mod = 1000000007;
int pb(int a,int b) {int res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a*=a;a%=mod;}return res;}
signed main(){
	int n,m,k;
	cin>>n>>m>>k;
	int u,v;
	for(int i=1;i<=2*k;i++){
		cin>>u>>v;
	}
	cout<<n*m-1+(n+m-2)<<endl;
	for(int i=1;i<n;i++)cout<<"U";
	for(int i=1;i<m;i++)cout<<"L";
	for(int i=1;i<n;i++)cout<<"D";
	for(int i=1;i<m;i++){
		if(i%2==1){
			cout<<"R";
			for(int j=1;j<n;j++){
				if(i==m-1&&j==n);else cout<<"U";
			}
		}
		else{
			cout<<"R";
			
			for(int j=1;j<n;j++){
				if(i==m-1&&j==n);else cout<<"D";
			}
		}
	}
}
