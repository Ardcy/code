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
typedef double db;
const int mod = 1000000007;
int pb(int a,int b) {int res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a*=a;a%=mod;}return res;}
int a[105000];
signed main(){
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		for(int i=1;i<=200;i++){
			a[i]=0;
		}
		int y;
		for(int i=1;i<=n;i++){
			cin>>y;
			a[y]=1;
		}
		int cnt = 0;
		for(int i=1;i<=200;i++){
			if(a[i]==0&&x)x--,a[i]=1;
			else if(a[i]==0&&x==0){
				cnt=i-1;
				break;
			}
			cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
