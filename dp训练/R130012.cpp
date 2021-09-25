#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n;
	cin>>n;
	int f;
	for(int i=1;i<=n;i++){
		cin>>f;
		if(f<=3)cout<<-1<<endl;
		else if(f%2==0)cout<<f/4<<endl;
		else if(f==9)cout<<1<<endl;
		else if(f<=12)cout<<-1<<endl;
		else cout<<1+(f-9)/4<<endl;
	}
	return 0;
}
