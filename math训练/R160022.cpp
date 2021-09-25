#include<bits/stdc++.h>
using namespace std;
signed main(){
	int s[3];
	int x,y,i;
	cin>>x>>y;
	s[0]=s[1]=s[2]=y;
	for(i=0;s[0]<x||s[1]<x||s[2]<x;i++){
		s[i%3]=s[(i+1)%3]+s[(i+2)%3]-1;
	}
	cout<<i<<endl;
}
