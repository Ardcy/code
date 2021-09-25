#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
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
int pb(int a,int b) {int res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a*=a;a%=mod;}return res;}
int a[105000];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int a,b,c,d;
		int x,y,x1,y1,x2,y2;
		cin>>a>>b>>c>>d;
		cin>>x>>y>>x1>>y1>>x2>>y2;
		int f = 1,f1=1;
		x=x+b-a;
		y=y+d-c;
		if(x<=x2&&x>=x1&&y<=y2&&y>=y1){
			if(b>0&&x1==x2){
				f=0;
			}
			if(c>0&&y1==y2){
				f=0;
			}
		}else f=0;
		if(f)cout<<"Yes"<<endl;else cout<<"No"<<endl;	
	}

	return 0;
}
