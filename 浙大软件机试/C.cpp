#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N = 2e5;
struct node1 {
	int a,b,c;
} e[N];
bool cmp(node1& A,node1& B) {
	if(A.c==B.c) {
		if(A.b==B.b) {
			return A.a<B.a;
		}
		return A.b<B.b;
	}
	return A.c>B.c;
}
int isfang[N];
vector<int>P[N];
map<int,int>score;
set<int>Se;
int ans1 = 0;
int ans2 = 0;
int ans3 = 0;
void dfs(int node) {
	ans3++;
	isfang[node]=1;
	ans1 += score[node];
	ans2 = min(ans2,node);
	for(auto p:P[node]) {
		if(isfang[p]==1)continue;
		else {
			dfs(p);
		}
	}
}
signed main() {
	int t;
	cin>>t;
	int s;
	while(t--) {
		int y;
		cin>>y;
		int n;
		cin>>n;
		for(int i=1; i<=n; i++) {
			int u;
			cin>>u;
			P[y].pb(u);
			P[u].pb(y);
		}
		cin>>s;
		score[y]=s;
		Se.insert(y);
	}
	int cnt = 1;
	for(auto p:Se) {
		ans1 = 0;
		ans2 = p;
		ans3 = 0;
		if(isfang[p]==0) {
			dfs(p);
			//cout<<ans2<<" "<<ans3<<" "<<ans1<<endl;
			e[cnt].a=ans2;
			e[cnt].b=ans3;
			e[cnt].c=ans1;
			cnt++;
		}
		//cout<<ans2<" "<<ans3<<" "<<ans1<<endl;
	}
	sort(e+1,e+cnt,cmp);
	cout<<cnt-1<<endl;
	for(int i=1; i<cnt; i++) {
		printf("%04d %d %d\n",e[i].a,e[i].b,e[i].c);
	}

}
