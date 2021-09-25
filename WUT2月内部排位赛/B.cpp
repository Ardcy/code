#include<bits/stdc++.h>
using namespace std;
#define INF 1e18
#define maxn 510
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define mset(x) memset(x,0,sizeof(x))
typedef pair<int, int> pii;
#define int long long
int t, n;
struct point{
	int x, y;
}p[maxn];
map< pii, int > tb;
map< pii, int >::iterator it;
bool cmp(const point& a, const point& b){
	return (a.x==b.x&&a.y<b.y) || a.x<b.x;
}
int gcd(int a, int b){
	if(b==0) return a;
	return gcd(b, a%b);
}
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		rep(i,1,n)	scanf("%lld%lld", &p[i].x, &p[i].y);
		sort(p+1, p+n+1, cmp);				
		int cnt=0;
		rep(i,1,n-2){
			tb.clear();
			rep(j,i+1,n){
				int dx = p[j].x - p[i].x;
				int dy = p[j].y - p[i].y;
				int d = gcd(dx, dy);
				dx = dx/d;
				dy = dy/d;
				tb[make_pair(dx,dy)]++;
			}
			for(it=tb.begin(); it!=tb.end(); it++){
				int x = it->second;
				if(x>=2)	
					cnt += x*(x-1)/2; 
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

