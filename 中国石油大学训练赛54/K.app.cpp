#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,x;
int ch(int r){
	int n=r;
	int s=0;
	while(n){
		n/=10;s++;
	}
	if(a*r+b*s<=x)return 1;else return 0;
}
signed  main(){

	cin>>a>>b>>x;
	int l=1,r=1e9;
	while(l<r){
		int mid=l+r+1 >> 1;
		if(ch(mid))l=mid;
		else r=mid-1;
	} 
	if(ch(l))cout<<l<<endl;
	else cout<<0<<endl;
	return 0;
}
