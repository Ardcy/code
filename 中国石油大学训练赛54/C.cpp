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
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const int mod = 1000000007;
int rnd(int x){return mrand()%x;}
int pb(int a,int b) {int res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a*=a;a%=mod;}return res;}
int a[105000];
int b[105000];
inline int read() {
    char ch = getchar(); int x = 0, f = 1;
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    } while('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    } return x * f;
}
inline void write(int x){
	if (x < 0) x = ~x + 1, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
set<int>Pr;
set<int>pp;
signed main(){
	int n,m;
	cin>>n>>m;
	int mi = n+1;
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	int cnt = 1 , u;
	int no = n;
	while(no>0){
//		cout<<cnt<<endl;
//		for(auto p:Pr)cout<<"p="<<p<<endl;
		u = mi;
//		cout<<mi<<endl;
		int f=0;
		for(int i=1;i<mi;i++){
//			cout<<i<<endl;
			if(i+a[i]>=mi&&f==0){
				f=1;
				no--;
				b[i]=cnt;
				u=min(u,i);
			}else if(f==1){
				if(i+a[i]>=mi)b[i]=cnt;else b[i]=cnt+1;
				no--;
			} 
		}
		mi=u;
		cnt++;	
	}
	int nn;
	for(int i=1;i<=m;i++){
		nn=read();
	//	cout<<b[nn]<<endl;
		write(b[nn]);printf(" ");
	}
	
	return 0;
}
