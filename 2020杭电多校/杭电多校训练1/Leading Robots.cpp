#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+4;
struct node{
	int p,a;
	bool operator<(const node &u)const{
		return p == u.p ? a > u.a : p > u.p;
	}
	bool operator==(const node &u)const{
		return p==u.p&&a==u.a;
	}
}e[N];
inline bool check(node& x1,node& x2,node& x3){
	if((long long)(x3.a-x1.a)*(x1.p-x2.p) < (long long)(x1.p-x3.p)*(x2.a-x1.a))return true;
	return false;
}
node stck[N];
signed main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		set<node>st;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&e[i].p,&e[i].a);
		}
		sort(e+1,e+n+1);
		for(int i=1;i<=n;i++){
			if(e[i]==e[i-1]){
				st.insert(e[i]);
			}
		}
		stack<node>stk;
		stk.push(e[1]);
		stck[1] = e[1];
		for(int i=2;i<=n;i++){
			if(e[i].a <= stk.top().a){
				continue;
			}
			if(stk.size()<2){
				if(e[i].a > stk.top().a){
					stk.push(e[i]);
				}
				continue;
			}
			while(stk.size() >= 2){
				node pre1 = stk.top();
				stk.pop();
				node pre2 = stk.top();
				if(check(pre2,pre1,e[i])){
					stk.push(pre1);
					break;
				}else{
					
				}
				if(stk.size()==1){
					break;
				}
			}
			stk.push(e[i]);
		}
		int cnt = 0;
		while(stk.size()){
			node pre = stk.top();
			if(st.count(pre)==1){	
			}else{
				cnt++;
			}
			stk.pop();
		}
		printf("%d\n",cnt);
	}
}