#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int a[12000];
	cin>>n;
	a[1]=1;
	a[2]=2;
	
	for(int i=3;i<=20;i++){
		a[i]=a[i-1]+a[i-2];
	}
	cout<<a[n]<<endl;
}
