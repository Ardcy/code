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
mt19937 mrand(random_device{}());
const int mod = 1000000007;
int rnd(int x){return mrand()%x;}
int pb(int a,int b) {int res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a*=a;a%=mod;}return res;}
signed main(){
	int t;
	cin>>t;
	string s;
	while(t--){
		cin>>s;
		int ans = 0;
		int l = s.length();
		int r = 0;
		int pos = s.find("1",r);
		while(pos!=string::npos) {
			ans++; 
			for(int i=2;i<=18;i++){
				if(pos+i-1<=l)if(i==2&&s.substr(pos,i)=="10")ans++;
				if(pos+i>l)break;
				int u = stol(s.substr(pos,i),0,2);
				if(pos-(u-i)<0)break;
				if(u-i>0&&(s.substr(pos-(u-i),u-i).find("1")==string::npos))ans++;
			}
			r=pos;
			pos=s.find("1",r+1);	
		} 
		cout<<ans<<endl;
	}
	return 0;
}
