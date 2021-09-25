#include<bits/stdc++.h>
using namespace std;
int a[10000][2];
int b[10000][2];
signed main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	for(int i=1;i<=100;i++){
		cin>>a[i][0]>>a[i][1];
	}
	for(int i=1;i<=100;i++){
		cin>>b[i][0]>>b[i][1];
	}
	for(int i=1;i<=100;i++){
		if(a[i][1]!=b[i][1]){
			cout<<"wa!!!!!!!!      "<<i<<endl;
		}
	}
	return 0;
	
}
