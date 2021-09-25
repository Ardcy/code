#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;}return ans;};

stack<pair<int,int> >P;
signed main(){
	int t;
	P.push(mp(19,4));
	cout<<P.top().first<<endl;
	
	cout<<P.size();
	return 0;
}


