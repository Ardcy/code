#include<bits/stdc++.h>
using namespace std;
int a[105000]={0};
int b[105000]={0};
set<int>c;
int main(){
	int m,n,d;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(c.count(a[i])==0)b[i]=b[i+1]+1,c.insert(a[i]);
		else b[i]=b[i+1];
	}
	for(int i=1;i<=m;i++){
		cin>>d;
		cout<<b[d]<<endl;
	}
}
