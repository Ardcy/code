#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int x,y;
	bool operator < (const node&p)const{
		return x==p.x?y<p.y:x < p.x;
	}
};
void solve(){
	map<node,int>mp;
	int n,m;
	cin >> n >> m;
	queue<node>p;
	p.push({n,m});
	int ans = 0;
	int flag = 1;
	while(!p.empty()){
		node now = p.front();p.pop();
		int x = now.x,y = now.y;
		int cnt = 0;
		flag = 1;
		for(int i=-1;i<=1;i++){
			for(int j=-1;j<=1;j++){
				if(x+i==y+j){
					flag = 0;break;
				}
				if(i==0&&j==0)continue;
				if(__gcd(x+i,y+j)!=1){
					cnt++;
					node pp = (node){x+i,y+j};
					if(!mp[pp]){
						p.push(pp);
					}
				}

			}
		}
		if(flag==0)break;	
		mp[now] = cnt;
		ans += cnt;
	}
	ans = 0;
	for(auto u:mp){
		node p1 = u.first;
		ans += u.second ;
	}
	if(flag==0){
		cout<<"0/1" << endl;
	}else{
		ans += mp.size();
		cout << (mp[{n,m}]+1 )/__gcd(mp[{n,m}]+1 ,ans)<< "/" << ans/(__gcd(mp[{n,m}]+1 ,ans)) << endl;
	}
	
}
signed main(){
	

	int T;
	cin >> T;
	while(T--){
		solve();
	}
}