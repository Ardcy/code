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
int is_palindrome(string s) {
   return equal(s.begin(), s.begin() + s.length() /2, s.rbegin());
}
int pb(int a,int b) {int res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a*=a;a%=mod;}return res;}
signed main(){
	int t;
	cin>>t;
	string t1;
	while(t--){
		string s;
		cin>>s;
		int k = 0;
		int l = s.length();
		for(int i=0;i<s.length();i++){
			if(s[i]==s[l-1-i]&&i<(l-1-i))k++;
			else break;
		}
		if(2*k>=l-1){
			cout<<s<<endl;
		}
		else{
			string q = s.substr(k,l-2*k);
			int re = 0;
			int i1 = 0;
			int j1 = q.length() - 1;
			
			int hlen = j1;
			while(i1<=j1){
				if(q[i1]==q[j1]){
					++i1;--j1;
				}
				else{
					i1=0;--j1;hlen = j1;
				}
			}
			re = hlen+1;
			int ans1=re;
			int ans2=0;
			reverse(q.begin(), q.end());
			re = 0;
			i1 = 0;
			j1 = q.length() - 1;
			hlen = j1;
			while(i1<=j1){
				if(q[i1]==q[j1]){
					++i1;--j1;
				}
				else{
					i1=0;--j1;hlen = j1;
				}
			}
			re=hlen+1;
			ans2=re;
			if(ans1>ans2){
				 t1 = s.substr(0,k) +s.substr(k,ans1)+ s.substr(l-k,k);
				cout<<t1<<endl; 
				
			}
			else{
				 t1 = s.substr(0,k) +s.substr(l-k-ans2,ans2)+ s.substr(l-k,k);
				cout<<t1<<endl;
			} 
		}
		
	}

	return 0;
}
