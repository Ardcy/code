#include<bits/stdc++.h>
using namespace std;
int main(){
	int a;
	cin>>a;
	int cnt=0;
	cnt = a/100;
	a%=100;
	cnt += a/20;
	a%=20;
	cnt += a/10;
	a%=10;
	cnt += a/5;
	a%=5;
	cnt += a/2;
	a%=2;
	cnt+=a;
	cout<<cnt;
}
