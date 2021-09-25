#include<bits/stdc++.h>
using namespace std;
vector<int>P[200005];
signed main(){
	for(int i=2;i<=200000;i++)for(int j=2*i;j<=200000;j+=i)P[j].push_back(i);

	int t;
	t = 1;
	while(t--){
		int n;
		cin >> n;
		vector<pair<int,int>>ans;
		set<int>ui;
		for(int i=n;i>=2;i--){
			if(P[i].size()==0){
				set<int>fe;
				for(int j = i;j<=n;j+=i){
					if(ui.count(j)==0){
						fe.insert(j);
						ui.insert(j);
					}
				}
				if(fe.size()%2==1&&fe.size()>2){
					fe.erase(2*i);
					ui.erase(2*i);
				}
				if(fe.size()==1){
					continue;
				}
				vector<int>fe1;
				for(auto pp:fe){
					fe1.push_back(pp);
				}
				for(int i=0;i<fe1.size();i+=2){
					ans.push_back(make_pair(fe1[i],fe1[i+1]));
				}
			}
		}
		cout << ans.size() << " ";
		for(auto f:ans){
			cout << f.first <<" " << f.second << " ";
		}cout << endl;
	}
}