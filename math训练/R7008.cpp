#include<bits/stdc++.h>
using namespace std;
signed main(){
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	if(a*b+2*d<a*c+2*e)cout<<"First"<<endl;
	if(a*b+2*d>a*c+2*e)cout<<"Second"<<endl;
	if(a*b+2*d==a*c+2*e)cout<<"Friendship"<<endl;
	return 0;
}
