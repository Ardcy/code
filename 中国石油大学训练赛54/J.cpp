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
int a[26];
int b[26];
signed main(){
	string s;
	string t;
	cin>>s>>t;
	int l=s.length();
	for(int i=0;i<l;i++)a[s[i]-'a']++;
	for(int i=0;i<l;i++)b[t[i]-'a']++;
	sort(a,a+26);
	sort(b,b+26);
	for(int i=0;i<26;i++)if(a[i]!=b[i]){
		cout<<"No"<<endl;
		return 0;
	}
	cout<<"Yes"<<endl;
	return 0;
}
