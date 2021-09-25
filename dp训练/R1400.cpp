#include<bits/stdc++.h>
using namespace std;
int a[200];
int b[200];
#define int long long
signed main(){
	int m,n;
	cin>>m>>n;
	if(n==0&m==1)cout<<"0 0"<<endl;
	else if(n>m*9||n==0)cout<<"-1 -1"<<endl;
	else{
		a[1]=1;
		b[1]=1;
		int r=n-1;
		for(int it=m;it>=1;it--){
			while(r){
				a[it]++;
				r--;
				if(a[it]==9)break;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<a[i];
		}
		cout<<" ";
		r=n-1;
		for(int it=1;it<=m;it++){
			while(r){
				b[it]++;
				r--;
				if(b[it]==9)break;
			}
		}
		for(int it=1;it<=m;it++){
			cout<<b[it];
		}
		cout<<endl;	
	}
	return 0;
}
