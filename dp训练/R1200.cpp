#include<bits/stdc++.h>
using namespace std;
int c[104];
int main(){
	int n;
	cin>>n;
	int a=0,b=0;
	int ans = 0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		if(c[i]==1)b++;
		if(c[i]==0)a++;
		else a--;
		ans = max(ans,a);
		if(a<0)a=0;
	}
	if(ans == 0)cout<<b-1<<endl;
	else  
	cout<<ans+b<<endl;
}
