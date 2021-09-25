#include<bits/stdc++.h>
using namespace std;
int n,a[200000],b[200000],c[200000];
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>a[i]>>b[i];
		c[a[i]]++;
		c[b[i]]++;
	}
	int de,dg;
	for(int i=1;i<=n;i++){
		if(c[i]==1){
			de=i;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(c[i]==1&&i!=de){
			dg=i;
			break;
		}
	}
	int flag = 0,hu=0;
	for(int i=1;i<=n;i++){
		if(c[i]==1&&i!=de&&i!=dg){
			hu=i;
			break;
		}
	}
	if(hu)flag=1;
	for(int i=1;i<n;i++){
		if(a[i]==de||b[i]==de){
			de=i;break;
		}	
	}
	for(int i=1;i<n;i++){
		if(a[i]==dg||b[i]==dg){
			dg=i;break;
		}	
	}
	for(int i=1;i<n;i++){
		if(a[i]==hu||b[i]==hu){
			hu=i;break;
		}	
	}
//	cout<<de<<" "<<dg<<endl;
	if(flag==1){
		int cnt=3;
		for(int i=1;i<=n-1;i++){
			if(i==de)cout<<0<<endl;
			else if(i==dg)cout<<1<<endl;
			else if(i==hu)cout<<2<<endl;
			else cout<<(cnt++)<<endl;
		} 
	}
	else {
		int cnt=2;
		for(int i=1;i<=n-1;i++){
			if(i==de)cout<<0<<endl;
			else if(i==dg)cout<<1<<endl;
			else cout<<(cnt++)<<endl;
		} 		
	}

}
