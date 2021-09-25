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
	while(t--){
		string s;
		cin>>s;
		int k = 0;
		int l = s.length();
		for(int i=0;i<s.length();i++){
			if(s[i]==s[l-1-i]&&i<(l-1-i))k++;
			else break;
		}
		int y1=0,y2=0;
		
		for(int j=l-2*k;j>=1;j--){
			if(is_palindrome(s.substr(k,j))){
				y1=j;break;
			}
		}
		for(int j=l-2*k;j>=1;j--){
			if(is_palindrome(s.substr(l-k-j,j))){
				y2=j;break;
			}
		}
		if(y1>y2){
			string t = s.substr(0,k) +s.substr(k,y1)+ s.substr(l-k,k);
			cout<<t<<endl; 
		} 
		
		else{
			string t = s.substr(0,k) +s.substr(l-k-y2,y2)+ s.substr(l-k,k);
			cout<<t<<endl;
			 
		} 
		
		
	}

	return 0;
}
