#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define mp make_pair
#define pb push_back
vector<int>P;
vector<int>Q;
int solve(vector<int> C){
    if(C.size()==1)return 0;
	int l = C.size();
	int last = C[l-1];
	int ans = inf;
	for(auto p:C){
		int midl = (last+p)/2;
		int y  = *(lower_bound(C.begin(),C.end(),p));
		if(y==0)ans = min(ans,last-midl);
		else{
			y=*(lower_bound(C.begin(),C.end(),p)-1);
			int ans1 = max(y,last-midl);
			ans=min(ans1,ans);
		}
	}
	return ans;
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		P.resize(0);Q.resize(0);
		int n;
		cin>>n;
		int u;
		int w1=0,w2=0;
		for(int i=1;i<=n;i++){
			cin>>u;
			if(u==0)continue;
			u>0?(P.pb(u),w1=max(w1,u)):(Q.pb(-u),w2=max(w2,-u));	
		}
		
		P.pb(0);Q.pb(0);
		sort(P.begin(),P.end());sort(Q.begin(),Q.end());
		int ans1 = solve(P);
		int ans2 = solve(Q);
	
		cout<<min(max(w1,ans2),max(w2,ans1))<<endl;
	}
	return 0;
}

