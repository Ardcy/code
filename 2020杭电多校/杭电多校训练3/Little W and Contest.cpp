#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+5;
const int maxn = 1e9+7;
int p1[N],p2[N];
int s1,s2;
int sum;
int fa[N];
int my[N];
int n;
void init(){
	s1 = 0,s2 = 0;
	for(int i=1;i<=n;i++){
		fa[i] = i;
		if(my[i]==1){
			p1[i] = 1;
			p2[i] = 0;s1++;
		}else{
			p1[i] = 0,p2[i] = 1,s2++;
		}

	}
	sum = s2*(s2-1)*(s2-2)/2/3+s2*(s2-1)/2*s1;
	sum %= maxn;
}
int find(int x){
	if(x==fa[x]){
		return x;
	}else{
		return fa[x] = find(fa[x]);
	}
}
void merge(int u,int v){
	int ru = find(u),rv = find(v);
	fa[rv] = ru;
	int now1 = s1-p1[ru] - p1[rv];
	int now2 = s2-p2[ru] - p2[rv];
	sum = sum - p2[ru]*p2[rv]*(now2+now1) - p1[ru]*p2[rv]*now2-p2[ru]*p1[rv]*now2;
	while(sum < 0)sum+=maxn;
	sum%=maxn;
	p1[ru]+=p1[rv];
	p2[ru]+=p2[rv];
}
signed main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=1;i<=n;i++){
			scanf("%lld",&my[i]);
		}
		init();
		cout << sum << endl;
		int u,v;
		for(int i=1;i<n;i++){
			scanf("%lld%lld",&u,&v);
			merge(u,v);
			cout << sum << endl;
		}
	}
}