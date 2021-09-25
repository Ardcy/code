#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int a,b;
	cin>>a>>b;
	int cnt = 0;
	if(a>b)swap(a,b);
	if(a==b){cout<<1<<endl;return 0;}
	while(a!=b){
		cnt+=b/a;
		b-=b/a*a;
		if(b==0)break;
		else swap(a,b);
	}
	cout<<cnt<<endl;
	return 0;
}
