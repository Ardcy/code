#include<bits/stdc++.h>
using namespace std;
signed main(){
	double a,b,c;
	cin>>a>>b>>c;
	double sum = 0.0;
	double p1,p2,p3;
	p1 = max({a,b,c});
	if(p1==a)printf("W ");
	if(p1==b)printf("T ");
	if(p1==c)printf("L ");
	cin>>a>>b>>c;
	p2=max({a,b,c});
	if(p2==a)printf("W ");
	if(p2==b)printf("T ");
	if(p2==c)printf("L ");
	
	cin>>a>>b>>c;
	p3=max({a,b,c});
	if(p3==a)printf("W ");
	if(p3==b)printf("T ");
	if(p3==c)printf("L ");
	
	sum = (p1*p2*p3*0.65-1)*2;
	printf("%.2f\n",sum);
}
