#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<'='<<x<<endl
using namespace std;
#define int long long
struct node{
	int x,y,z;
	operator < (const node& t)const{
		return x<t.x;
	}	
}e[120];
int a[120],b[120];
signed  main(){
	int T;
	cin>>T;
	while(T--){
		int a,b;
		cin>>a>>b;
		int cnt = 1; 
		for(int i=1;i<=a;i++){
			cin>>e[cnt].x>>e[cnt].y>>e[cnt].z;
			cnt++;
		}
		sort(e,e+cnt);
		e[0].x=0;e[0].y=b;e[0].z=b;
		int f;
		int flag = 0; 
		for(int i=1;i<cnt;i++){
			f = e[i].x-e[i-1].x;
			if(e[i-1].z+f<e[i].y||e[i-1].y-f>e[i].z){
				flag = 1;
			}
			else{
				e[i].y=max(e[i-1].y-f,e[i].y);
				e[i].z=min(e[i-1].z+f,e[i].z);
			}
		}
		if(flag == 1)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}
