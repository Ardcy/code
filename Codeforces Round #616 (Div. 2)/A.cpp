#include<bits/stdc++.h>
using namespace std;
int a[3050];
inline void solve(){
	memset(a,0,sizeof(a));
	int u;
	cin>>u;
	getchar();
	int e=0,b=0,f1,f2;
	for(int i=1;i<=u;i++){
		
		a[i] = getchar()- '0';
		if(a[i]%2&&!e)e=a[i];
		if(a[i]%2&&e)b=a[i];
	}
	if(b)cout<<e<<b<<endl;
	else cout<<-1<<endl;
}

int main(){
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
