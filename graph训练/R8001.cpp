#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[20500];
int v[20500];
signed main(){
	int n;
	cin>>n;
	int cnt = 0; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<=n;i++){
		if(a[a[a[i]]]==i){
			cout<<"YES"<<endl;return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;	
}
