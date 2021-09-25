#include<bits/stdc++.h>
using namespace std;


struct node{
	int x,length;
	bool operator<(const node& p)const{
		return x==p.x?length < p.length:x < p.x;
		// return length==p.length?x<p.x:length < p.length;
	}
	bool operator>(const node& p)const{
		return length==p.length?x>p.x:length > p.length;
	}
};
struct person{
	vector<node> P;
	int vis[100];
	int num;
}e[3];
int arr[100];
signed main(){
	int n,m;
	cin >> n >> m;
	multiset<int>P;
	set<int>p;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
		P.insert(arr[i]);p.insert(arr[i]);
	}
	for(auto u:p){
		e[0].P.push_back({u,P.count(u)});
	}
	sort(e[0].P.begin(),e[0].P.end());
	e[0].num = e[0].P.size();

	P.clear();p.clear();
	for(int i=1;i<=n;i++){
		cin >> arr[i];
		P.insert(arr[i]);p.insert(arr[i]);
	}
	for(auto u:p){
		e[1].P.push_back({u,P.count(u)});
	}
	sort(e[1].P.begin(),e[1].P.end());
	e[1].num = e[1].P.size();

	P.clear();p.clear();
	for(int i=1;i<=n;i++){
		cin >> arr[i];
		P.insert(arr[i]);p.insert(arr[i]);
	}
	for(auto u:p){
		e[2].P.push_back({u,P.count(u)});
	}
	sort(e[2].P.begin(),e[2].P.end());
	e[2].num = e[2].P.size();

	node u = {0,0};
	int pcnt = 3;
	int cntt = 0;
	while(pcnt){

		if(cntt==2){
			u = {0,0};
		}
		int flag = 0;
		// cout << u.x << " " << u.length <<endl;

		for(int i=0;i < e[pcnt%3].P.size();i++){
			if(u.length&&e[pcnt%3].P[i].x > u.x && e[pcnt%3].P[i].length>=u.length  && e[pcnt%3].vis[i]==0){
				if(e[pcnt%3].P[i].length==u.length){
					e[pcnt%3].vis[i] = 1;
					e[pcnt%3].num--;
				}else{
					e[pcnt%3].P[i].length-=u.length;
				}

				flag = 1;
				// cout << pcnt%3 << " " << e[pcnt%3].P[i].x << " " << u.length << endl;
				u = {e[pcnt%3].P[i].x,u.length} ;
				break;
			}
		}
		if(flag==0)
		for(int i=0;i < e[pcnt%3].P.size();i++){
			if( e[pcnt%3].P[i].length>u.length  && e[pcnt%3].vis[i]==0){
				e[pcnt%3].P[i].length -= u.length+1;
				if(e[pcnt%3].P[i].length==0){
					e[pcnt%3].num-=1;
				}
				flag = 1;
				// cout << pcnt%3 << " " << e[pcnt%3].P[i].x << " " << u.length+1 << endl; 
				u = {e[pcnt%3].P[i].x,u.length+1} ;
				break;
			}
		}	
		
		if(flag==0){
			cntt++;
		}else{
			cntt=0;
		}
		if(e[pcnt%3].num==0){
			cout << pcnt%3 +1 << endl;
			break;
		}
		pcnt++;
	}

}