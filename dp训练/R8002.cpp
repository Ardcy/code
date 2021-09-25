#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	cin>>a;
	if(a==1){
		cout<<1<<endl;
		return 0;
	}
	if(a==2){
		cout<<5<<endl;
		return 0;
	}
	long long int ans = 5;
	for(int i=3;i<=a;i++){
		ans+=3*i;
	}
	cout<<ans<<endl;
}
