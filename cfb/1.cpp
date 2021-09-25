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
int a[40]; 
signed main(){
	int n,k;
	cin>>n>>k; 
	string s;
	cin>>s;
	if(k==0){
		cout<<s<<endl;return 0;
	}
	string t;
	for(int i=0;i<s.length();i++){
		if(s.length()==1)t+="0";
		else if(s[i]>'1'&&i==0&&k)t+="1",k--;
		else if(i>0&&s[i]>'0'&&k)t+="0",k--;
		else t+=s[i];
	}
	cout<<t<<endl;
	return 0;
}
