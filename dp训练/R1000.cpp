#include<bits/stdc++.h>
using namespace std;
#define int long long
int po(int a,int b){
	int ans = 1;
	while(b){
		if(b&1)ans*=a;
		a*=a;
		b>>=1;
	}
	return ans;
}
signed main(){
	int n;
	cin>>n;
	if(n%2){
		cout<<0<<endl;
	}
	else{
		cout<<po(2,n/2)<<endl;
	}
}
