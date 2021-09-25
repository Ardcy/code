#include<bits/stdc++.h>
#define int long long
#define sf(n) scanf("%lld",&n)
#define sff(a,b) scanf("%lld%lld",&a,&b)
#define sfff(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define debug printf("Here\n")
#define out(x) cout << x << endl
#define out2(x,y) cout << x << " " << y << endl
#define out3(x,y,z) cout << x << " " << y <<" " << z << endl
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
using namespace std;

inline int read(){
	int s = 0,w = 1;
	char ch = getchar();
	while(ch < '0'||ch > '9'){
		if(ch=='-')w = -1;
		ch = getchar();
	}
	while(ch >= '0'&&ch <='9'){
		s = s*10+ch - '0',ch = getchar();
	}
	return s*w;
} 
void yes(){cout << "YES" << endl;}
void no(){cout <<"NO" << endl;}

const int  MAXN = 2e5+10;
const int INF = 0x3f3f3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-9;
const double PI = acos(-1.0);

int n;
int arr[MAXN];


signed main(){
	
	while(cin >> n){
		int x = 0,xt = 0,xtC = 0,xtCp = 0,xtCpc = 0;int c = 0,cp = 0,cpC = 0,cpCt = 0,cpCtx = 0;
		string s;
		cin >> s;
		
		for(int i=0;i<s.length();i++){
			if(s[i]=='x')x++;
			if(s[i]=='t'&&x)x--,xt++;
			if(s[i]=='C'&&xt)xt--,xtC++;
			if(s[i]=='p'&&xtC)xtC--,xtCp++;
			if(s[i]=='c'&&xtCp)xtCp--,xtCpc++;
		}
		for(int i=s.length()-1;i>=0;i--){
			if(s[i]=='c')c++;
			if(s[i]=='p'&&c)c--,cp++;
			if(s[i]=='C'&&cp)cp--,cpC++;
			if(s[i]=='t'&&cpC)cpC--,cpCt++;
			if(s[i]=='x'&&cpCt)cpCt--,cpCtx++;
		}
		printf("%lld\n",xtCpc);	
	}
	
	
}
