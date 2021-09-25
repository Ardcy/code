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

int char1[30],char2[30];
signed main(){
	
	string s,t;
	
	while(cin >> s >> t){
		for(int i=0;i<30;i++){
			char1[i] = char2[i] = 0;
		}	
		int flag2  = 1;
		if(s.length()!=t.length()){
			cout <<"No" << endl;
			continue;
		}
		for(int i=0;i<s.length();i++){
			char1[s[i]-'a']++;
			char2[t[i]-'a']++;
			if(s[i]!=t[i])flag2 = 0;
		}
		int flag = 1;
		
		for(int i=0;i<30;i++)if(char1[i]!=char2[i]){
			flag = 0;
		}
		if(flag == 0){
			cout<< "No" << endl;
		}
		
		else if(s[0]!=t[0]||s[s.length()-1]!=t[t.length()-1]){
			cout << "No" << endl; 
		}else{
			if(flag2){
				cout << "Equal" << endl;
			}else{
				cout <<"Yes" << endl;
			}
		}
	}
	
	
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
}
