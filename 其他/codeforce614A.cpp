#include<bits/stdc++.h>
using namespace std;
long long int a[100];
int main(){
	long long int x0,y0,ax,ay,bx,by;
	scanf("%lld%lld%lld%lld%lld%lld",&x0,&y0,&ax,&ay,&bx,&by);
	long long int xs,ys,t;
	scanf("%lldlldlld",&xs,&ys,&t);
	long long int yu[100]={0};
	int sum = 0;
	int i;
	for( i=1;i<=100;i++){
		if(x0<xs||y0<ys){
			yu[i] = abs((ax*x0+bx)-x0) +abs((ay*y0+by)-y0);
			x0 = (ax*x0+bx);
			y0 = (ay*y0+by);
		}
		if(x0<0||y0<0)break;
		
				
	}
	
	if(abs(x0-xs)+abs(y0-ys)<t)sum++;
	long long int yy=abs(x0-xs)+abs(y0-ys);
	for(;i>=0;--i){
		if(yy+yu[i]<=t)sum++;
		yy = yy+yu[i]; 
	}
	cout<<sum<<endl;
	

}




 
