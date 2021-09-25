#include<bits/stdc++.h>
using namespace std;
int u(int a){
	int ans = 0;
	while(a){
		ans=max(a%10,ans);
		a/=10;
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	int e;
	int cnt = 0;
	while(n){
		cnt++;
		e = n;
		e = u(e);
		n-=e;
	}
	cout<<cnt<<endl;
}
