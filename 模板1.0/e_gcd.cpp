#include<bits/stdc++.h>
using namespace std;
void e_gcd(int a,int b,int &gcd, int &x, int &y){
	if(b==0){
		x=1;y=0;gcd=a;
		cout<<x<<" "<<y<<endl;
	}
	else{
		e_gcd(b,a%b,gcd,y,x);
		y-=x*(a/b);
		cout<<x<<" "<<y<<" "<<a<<" "<<b<<endl;
	}
}
// head 求逆元
int cal(int a,int m){
	int x,y,gcd;
	e_gcd(a,m,gcd,x,y);
	if(1%gcd!=0)return -1;
	return (x%m+m)%m;
} 
//手模拟 
//void egcd(int a,int b,int &gcd,int &x,int &y){
//	if(b==0){
//		x=1;b=0;gcd=a;
//	}else{
//		egcd(b,a%b,gcd,y,x);
//		y-=x*(a/b);
//	}
//}
//int cal(int a,int m){
//	int x,y,gcd;
//	egcd(a,m,gcd,x,y);
//	if(gcd!=1)return -1;
//	else{
//		return (x%m+m)%m;
//	}
//} 
signed main(){
	int a,b;
	int x,y,gcd;
	//e_gcd(18,8,gcd,x,y);
	//cout<<gcd<<" "<<x<<" "<<y<<endl;
	cout<<cal(25,26);
}
//signed main(){
//	
//}
