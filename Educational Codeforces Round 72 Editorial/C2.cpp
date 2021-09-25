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
int zeros[205000];
signed main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int l=s.length();
		for(int i=1;i<s.length();i++){
			if(s[i-1]=='0')zeros[i]=zeros[i-1]+1;
			else zeros[i]=0;
		}
		int ans = 0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='1'){
				ans++;
				int cur = 1;
				for(int j=2;j<=20&&i+j<=l;j++)
				{
					cur = 2*cur + (s[i+j-1]-'0');
					if(cur-j<=zeros[i])ans++;	
				}
			}
		}
		cout<<ans<<endl;
		
	}

	return 0;
}
