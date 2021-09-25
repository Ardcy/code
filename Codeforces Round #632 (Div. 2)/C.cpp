#include<bits/stdc++.h>
using namespace std;
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
const int mod = 1000000007;
int qp(int a,int b) {int res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a*=a;a%=mod;}return res;}
int a[305000];
struct node{
	int x,y;
}sum[405000];
bool cmp(node a,node b){
	if(a.x==b.x)return a.y<b.y;
	else return a.x<b.x;
}
struct nod{
	int x,y;
}jt[605000];
int c[305000];
bool cmp1(nod a,nod b){
	if(a.x==b.x)return a.y<b.y;
	else return a.x<b.x;
}
int d[605000];
int e[605000];
int f1[605000];
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],sum[i].x=sum[i-1].x+a[i],sum[i].y=i;
	sort(sum+1,sum+n+1,cmp);
	for(int i=1;i<=n;i++)c[i]=sum[i].x;
	int cnt = 0;
//	cout<<"--------"<<endl;
//	for(int i=1;i<=n;i++)cout<<sum[i].x<<" "<<sum[i].y<<endl;
//	cout<<"--------"<<endl; 
	for(int i=2;i<=n;i++){
		if(c[i]==c[i-1]){
			cnt++;
			jt[cnt].x=sum[i-1].y+1;
			jt[cnt].y=sum[i].y;	
					
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			cnt++;
			jt[cnt].x=i;jt[cnt].y=i;
		}
		if(sum[i].x==0){
			cnt++;
			jt[cnt].x=1;jt[cnt].y=sum[i].y;
		}
	}
	jt[cnt+1].x=n+1;jt[cnt+1].y=n+1;
	cnt++;
	sort(jt+1,jt+cnt+1,cmp1);
	for(int i=1;i<=cnt;i++)d[i]=jt[i].x,e[i]=jt[i].y;
	int ans = 0;
	f1[cnt+1]=10000000000;
	for(int i=cnt;i>=1;i--)f1[i]=min(f1[i+1],e[i]);
	for(int i=1;i<=n;i++){
		int u=lower_bound(d+1,d+cnt+1,i)-d;
//		int u1 = lower_bound(e+u,e+cnt+1,i)-e;
//		ans += e[u1]-i;
		ans+=f1[u]-i;
//		cout<<d[u]<<" "<<e[u1]<<endl;
//		cout<<e[u1]-i<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
