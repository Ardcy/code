#include<iostream>
using namespace std;
int a,b,i,m,t=1,g[10];
int main(){
	cin>>a;    
	while(a){
		b=a%10;
		for(i=9;i>9-b;i--)g[i]+=t;
		if(b>m)m=b;
		t*=10;
		a/=10;
	}		
	cout<<m<<endl;
	for(i=0;i<10;i++){
		if(g[i])cout<<g[i]<<' ';
	}
	return 0;
}
