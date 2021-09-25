#include<bits/stdc++.h>
using namespace std;
signed main(){
	int n;
	while(~scanf("%d",&n)){
		map<int,int>P;
		for(int i=1;i<=n;i++){
			int u;
			scanf("%d",&u);
			P[u]++;
		}
		int f = 0;
		for(auto p:P){
			if(p.second%2)f=1;
		}
		if(f)printf("Zhen\n");else printf("Qiang\n");
	}
}
