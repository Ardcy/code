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
//VI P[105000];
map<PII,int>P;
set<int>A;
set<int>B;
set<int>C;
struct node{int x,y;
}e[400000];
signed main(){
	int n,m;
	cin>>n>>m;
	int u,v;
	int cnt = 1;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld",&u,&v);
		e[cnt].x=u,e[cnt].y=v;
		cnt++;
		P[mp(u,v)]=1;P[mp(v,u)]=1;
	}
	A.insert(2);
	int pos=0;
	for(int i=1;i<=n;i++){
		if(P[mp(2,i)]!=1&&i!=2)A.insert(i);else if(i!=2) pos=i,B.insert(i);
	}
	
	if(pos==0){
		cout<<-1<<endl;return 0;
	}
	for(int i=1;i<=n;i++){
		if(i!=pos){
			if(P[mp(pos,i)]&&A.find(i)==A.end()){
				B.erase(i);C.insert(i);
			}
		}
	}
	
	if(C.empty()){
		cout<<-1<<endl;return 0;
	}
	int f = 1;
	for(int i=1;i<=m;i++){
		if(A.find(e[i].x)==A.end()&&B.find(e[i].x)==B.end()&&C.find(e[i].x)==C.end())f=0;
		if(A.find(e[i].y)==A.end()&&B.find(e[i].y)==B.end()&&C.find(e[i].y)==C.end())f=0;
		if(A.find(e[i].x)!=A.end()&&A.find(e[i].y)!=A.end())f=0;
		if(B.find(e[i].x)!=B.end()&&B.find(e[i].y)!=B.end())f=0;
		if(C.find(e[i].x)!=C.end()&&C.find(e[i].y)!=C.end())f=0;
	}
	if(m!=(SZ(A)*SZ(B)+SZ(C)*SZ(B)+SZ(A)*SZ(C))){
		cout<<-1<<endl;return 0;
	}
	if(f==0){
		cout<<-1<<endl;return 0;
	}
	for(int i=1;i<=n;i++){
		if(A.find(i)!=A.end())cout<<1<<" ";
		if(B.find(i)!=B.end())cout<<2<<" ";
		if(C.find(i)!=C.end())cout<<3<<" ";
	}
	
	return 0;
}
