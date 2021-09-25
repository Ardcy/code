#include<bits/stdc++.h>
using namespace std;
int f(int n);
signed main(){
	int n;
	cin>>n;
	cout<<f(n)<<endl;
}
int f(int n){
	int i; int ans = 1;
	for(int i=1;i<=n;i++){
		ans*=i;
	}
	return ans;
}
