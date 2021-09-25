#include<bits/stdc++.h>
using namespace std;
unsigned long random(unsigned long m,unsigned long n){
	srand((unsigned long)time(0));
	return (unsigned long)(m+rand()%n);
}
long PowMod(long x,long y,long n){
	long s,t,u;
	s = 1;
	t = x;
	u = y;
	while(u){
		if(u&1)s = (s*t)%n;
		u>>=1;
		t = (t*t)%n;		
	}
	return s;
}
int RabinMillerKnl(unsigned long n){
	unsigned long b,m,j,v,i;
	m = n-1;
	j = 0;
	while(!(m&1)){
		++j;
		m>>=1;
	}
	b = random(2,m);
	v = PowMod(b,m,n);
	if(v==1){
		return 1;
	}
	i = 1;
	while(v != n-1){
		if(i==j){
			return 0;
		}
		v = PowMod(v,2,n);
		i++;
	}
	return 1;
}
int main(){
	unsigned long p;
	int count = 0;
	while(1){
		count = 0;
		cin >> p;
		for(int i=1;i<=10;i++){
			if(RabinMillerKnl(p)){
				count++;
			}
		}
		cout << count << endl;	
	}
	
}