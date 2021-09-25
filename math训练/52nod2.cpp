#include<bits/stdc++.h>
#define ls (now<<1)
#define rs (now<<1|1)
using namespace std;
const int N=200010,M=5000010,bound=200000;
int n,l,t,top,num;
int a[N],mmin[N],mmax[N];
bool tf[N];
vector<int> d[N];
struct node {
	int pos,x;
	bool operator<(const node q)const {
		return pos<q.pos;
	}
} X,Y;
struct ques {
	int x,y,c;
	bool operator<(const ques q)const {
		return y<q.y;
	}
} q[N<<4];
set<node> S;
set<node>::iterator it,last;
void read(int&x) {
	char ch=getchar();
	x=0;
	while(ch<'0' || ch>'9') ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
}
void solve() {
	sort(q+1,q+1+t);
	S.clear();
	int now=0;
	long long ans=0,tot=0;
	S.insert((node) {
		n+1,0
	});
	for(int r=n+1; r<=2*n; r++) {
		int l=r-n;
		if(!S.empty()) {
			it=S.lower_bound((node) {
				l-1,0
			});
			X=*it;
			if(X.pos==l-1) S.erase(it);
			ans-=X.x;
		}
		S.insert((node) {
			l-1,1e9
		});
		while(now<t && q[now+1].y==r) {
			now++;
			it=S.lower_bound((node) {
				q[now].x,0
			});
			X=*it;
			it--;
			last=it;
			Y=*it;
			it++;
			if(X.x>=q[now].c) continue;
			if(X.pos==q[now].x) S.erase(it);
			S.insert((node) {
				q[now].x,q[now].c
			});
			ans+=1ll*(q[now].x-Y.pos)*(q[now].c-X.x);
			while(q[now].c>=Y.x) {
				it=last;
				last--;
				S.erase(it);
				X=Y;
				Y=*last;
				ans+=1ll*(X.pos-Y.pos)*(q[now].c-X.x);
			}
		}
		S.erase(S.begin());
		tot+=ans;
	}
	printf("%lld\n",tot);
}
void insert(int x,int y,int c) {
	q[++t]=(ques) {
		y,x+n,c
	};
}
int main() {
	read(n);
	for(int i=1; i<=n; i++) read(a[i]);
	for(int i=bound; i>=1; i--)
		for(int j=i; j<=bound; j+=i)
			d[j].push_back(i);
	for(int i=n; i>=1; i--)
		for(int j=0; j<d[a[i]].size(); j++) {
			if(!mmax[d[a[i]][j]]) mmax[d[a[i]][j]]=i;
			mmin[d[a[i]][j]]=i;
		}
	for(int i=1; i<=bound; i++)
		if(mmin[i]+2<=mmax[i])
			insert(mmin[i]+1,mmax[i]-1,i);
	for(int i=0; i<d[a[1]].size(); i++)
		tf[d[a[1]][i]]=true;
	int mmat=0;
	for(int i=2; i<n; i++) {
		int to=0;
		for(int j=0; j<d[a[i]].size(); j++)
			if(tf[d[a[i]][j]] && !to) to=d[a[i]][j];
			else tf[d[a[i]][j]]=true;
		if(to>mmat)
			mmat=to,insert(i+1,n,mmat);
	}
	memset(tf,false,sizeof(tf));
	for(int i=0; i<d[a[n]].size(); i++) 
		tf[d[a[n]][i]]=true;
	mmat=0;
	for(int i=n-1; i>=2; i--) {
		int to=0;
		for(int j=0; j<d[a[i]].size(); j++)
			if(tf[d[a[i]][j]] && !to) to=d[a[i]][j];
			else
				tf[d[a[i]][j]]=true;
		if(to>mmat)
			mmat=to,insert(1,i-1,mmat);
	}
	solve();
}

