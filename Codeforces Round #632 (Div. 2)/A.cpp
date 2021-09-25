#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define int long long
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef double db;
const int mod = 1000000007;
int qp(int a,int b) {int res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a*=a;a%=mod;}return res;}
signed main(){
	int t,n,a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		int cnt = 0;
		for(int i=1;i<=a;i++){
			for(int j=1;j<=b;j++){
				cnt++;
				if(cnt==1)cout<<"W";else cout<<"B";
			}
			cout<<endl;
		}
	} 
	return 0;
}
