#include<bits/stdc++.h>
using namespace std;
int T,h,m;

bool check(int x,int y){
	set<int>st;
	st.insert(0);
	st.insert(1);
	st.insert(2);st.insert(5);st.insert(8);
	if(st.count(x%10)!=1||st.count(x/10)!=1){
		return false;
	}
	if(st.count(y%10)!=1||st.count(y/10)!=1){
		return false;
	}
	map<int,int>mp;
	mp[0] = 0;
	mp[1] = 1;mp[2] = 5;mp[5] = 2;mp[8] = 8;
	if(mp[x%10]*10+mp[x/10] < m){
		if(mp[y%10]*10+mp[y/10]<h){
			return true;
		}
	}
	return false;
}

void next(int& x,int& y){
	if(y<m-1){
		y+=1;return;
	}
	if(y==m-1){
		if(x < h-1){
			x+=1,y=0;
			return;
		}else{
			x = 0;y = 0;
		}
	}
}


signed main(){
	cin >> T;
	while(T--){
		cin >> h >> m;
		int x,y;
		scanf("%d:%d",&x,&y);
		while(1){
			if(check(x,y)){
				printf("%02d:%02d\n",x,y);
				break;
			}else{
				next(x,y); 
			}
		}
	}
}