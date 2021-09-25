#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int d,e=1,ans = 0;
	int f=0;
	for(int i=1;i<=n;i++){
		cin>>d;
		if(d>0)ans+=abs(d-1),e*=1;
		if(d<0)ans+=abs(-1-d),e*=(-1);
		if(d==0)ans+=1,f=1;
	}
	if(e==-1&&f==0)cout<<ans+2<<endl;
	else cout<<ans<<endl;
}
