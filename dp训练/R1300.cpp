#include<bits/stdc++.h>
using namespace std;
int  d[15000];
int main(){
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	if(a>b)swap(a,b);
	if(b>c)swap(b,c);
	if(a>b)swap(a,b);
	d[a+10000]=1;
	d[b+10000]=1;
	d[c+10000]=1;
	for(int i=a+10001;i<=n+10000;i++){
		if(d[i-a]>=d[i])d[i]=max(d[i],d[i-a]+1);
		if(d[i-b]>=d[i])d[i]=max(d[i],d[i-b]+1);
		if(d[i-c]>=d[i])d[i]=max(d[i],d[i-c]+1);
		//cout<<"i="<<i-10000<<" d[i]="<<d[i]<<endl;
	}
	for(int i=1;i<=10;i++){
		//cout<<i<<" = "<<d[i+10000]<<endl;
	}
	cout<<d[10000+n]<<endl;
}
