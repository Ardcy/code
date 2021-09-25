#include<bits/stdc++.h>
using namespace std;

int exgcd(int a,int b,int& x,int& y){
	if(b==0){
		x=1,y=0;return a;
	}
	int c=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return c;
}



signed main(){

	double c = 3.0;
	printf("%d",c);
//	int a = 11;
//	int b = 33;
//	int x,y;
//	int c = exgcd(a,b,x,y);
//	cout<<"c="<<c<<endl;
//	cout<<"x="<<x<<endl;
//	cout<<"y="<<y<<endl;
}
