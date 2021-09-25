#include<bits/stdc++.h>
using namespace std;
map<int,int>P;
int a[1000000];
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		P[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(P[a[i]]==1){
			cout<<a[i]<<endl;
			return 0;
		}
	}
	cout<<"None"<<endl;
}
