#include<bits/stdc++.h>
using namespace std;
#define int long long
int qp(int a,int b){
	int res = 1;
	while(b){
		if(b&1)res*=a;
		a*=a;
		b>>=1;
	}
	return res;
}
int shuwei_dp(int n){
	if(n==0)return 0;
	if(n>=1&&n<=9)return 1;
	int f = log(n)/log(10);
	int f1 = qp(10,f);
	int p = n/f1;
	if(p==1){
		return shuwei_dp(f1-1)+shuwei_dp(n%f1)+n%f1+1;
	}else{
		return p*shuwei_dp(f1-1)+f1+shuwei_dp(n%f1);
	}
}

signed main(){
	int n;
	cin>>n;	
	cout<<shuwei_dp(n)<<endl;
}
