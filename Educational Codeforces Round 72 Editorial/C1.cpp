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
int zeros[1000000];
signed main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		zeros[0] = (s[0]=='0');
		for(int i=1;i<s.size();i++){
			if(s[i]=='0')zeros[i]=zeros[i-1]+1;
			else zeros[i]=0;
		}
		int n=s.size();
		int ret = 0;
		for(int i=0;i<n;i++){
			if(s[i]=='1'){
				int last = 0;
				if(i)last=zeros[i-1];
				int cur = 0;
				for(int j=i;j<min(i+20,n);j++){
					cur = cur*2+(s[j]-'0');
					int len = j-i+1;
					if(cur>=len&&cur<=len+last)ret++;
				}
			}
		}
		cout<<ret<<endl;
	}

	return 0;
}
