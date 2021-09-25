#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000];
signed main(){
	int n,k;
	cin>>n>>k;
	if(n<=2*k+1){
		cout<<1<<endl;
		cout<<(n+1)/2<<endl;
	}
	for(int i=1;i<=k+1;i++){
		int cnt=0;
		int f=0;
		for(int j=i;j<=n;j+=2*k+1){
			a[cnt++]=j;
			if(n-j-k>=k+1&&n-j-k<=2*k+1){
				f=1;
				a[cnt++]=j+2*k+1;
				break;
			}
		}
		if(f==1){
			cout<<cnt<<endl;
			for(int i=0;i<cnt;i++){
				cout<<a[i]<<" ";
			}
			cout<<endl;
			return 0;
		}
	}
	return 0;
}
