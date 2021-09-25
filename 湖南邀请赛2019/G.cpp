#include<bits/stdc++.h>
#define int long long
#define double long double
#define sf(n) scanf("%lld",&n)
#define sff(a,b) scanf("%lld%lld",&a,&b)
#define sfff(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define debug printf("Here\n");
#define out(x) printf("%lld\n",x)
#define out2(x,y) cout << x <<" " << y << endl
#define out3(x,y,z) cout << x << " " << y << " " << z << endl
#define pb push_back
#define fi first
#define se second 
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size)
using namespace std;

inline int read(){
	int s = 0,w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')w = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		s = s *10 + ch - '0',ch = getchar();
	}
	return s*w;
}
void yes(){cout << "YES" <<endl;
}
void no(){cout <<" NO"<<endl;}

const int MAXN = 2e5+10;
const int INF = 0x3f3f3f3f3f3f;
const int Mod = 1e9+7;
const double eps = 1e-8;
const double Pi = acos(-1.0); 
int n;
int arr[MAXN];
int dp[250500][4];
int dp1[250500][4];
signed main(){
	string s,t;
	while(cin >> s >> t){
		int cnt1 = 0,cnt2 = 0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='c')cnt1++;
		}
		for(int i=0;i<t.length();i++){
			if(t[i]=='c')cnt2++;
		}
		if(cnt1!=cnt2){
			cout << "No" << endl;
			continue;
		}
		for(int i=0;i<max(cnt1,cnt2)+100;i++){
			dp[i][1] = dp1[i][1] = dp[i][2] = dp1[i][2] = 0;
		}
		s = "c" + s + "c";
		t = "c" + t + "c";
		
		int c1 = 0, c2 = 0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='c')c1++;
			if(s[i]=='a')dp[c1][1]+=1,dp[c1][1]%=2;
			if(s[i]=='b')dp[c1][2]+=1,dp[c1][2]%=2;
		}
		for(int i=0;i<t.length();i++){
			if(t[i]=='c')c2++;
			if(t[i]=='a')dp1[c2][1]+=1,dp1[c2][1]%=2;
			if(t[i]=='b')dp1[c2][2]+=1,dp1[c2][2]%=2;
		}
		int flag = 1;
		for(int i=1;i<=c2;i++){
			if(dp1[i][1]!=dp[i][1]){
				flag = 0;
				break;
			}
			if(dp1[i][2]!=dp[i][2]){
				flag = 0;
				break;
			}
		}
		if(flag){
			cout <<"Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}
	return 0;
}
