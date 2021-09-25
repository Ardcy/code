#include<bits/stdc++.h>
#define N 100010
using namespace std;
int t,n,k,a[N];
bool ans;
int main(){
	//cin>>t;
	n=1000000;
	int cnt = 0;
	for(int i=1;i<=n;i++){
		for(int j=2*i;j<=n;j+=i)cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}

