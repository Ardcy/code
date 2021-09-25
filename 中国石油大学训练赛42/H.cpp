#include<bits/stdc++.h>
using namespace std;
int a[20];
int main(){
	int b,c;
	for(int i=1;i<=3;i++){
		cin>>b;
		a[b]++;
	}
	c=0;
	for(int i=1;i<=9;i++){
		if(a[i])c++;
	}
	if(c==2)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
