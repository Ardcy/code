#include<bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
struct Complex{
	double x,y;
	Complex(double _x = 0.0,double _y = 0.0){
		x = _x;
		y = _y;
	}
	Complex operator-(const Complex &b)const{
		return Complex(x - b.x,y - b.y);
	}
	Complex operator+(const Complex &b)const{
		return Complex(x + b.x,y + b.y);
	}
	Complex operator*(const Complex &b)const{
		return Complex(x * b.x - y*b.y,b.x*y + x* b.y);
	}
};

void change(Complex y[], int len)
{	
	int k;
	for(int i=1,j = len/2;i<len-1;i++){
		if(i<j)swap(y[i],y[j]);
		k = len/2;
		while(j >= k){
			j-=k;
			k/=2;
		}
		if(j<k)j+=k;
	}
}
void fft(Complex y[],int len,int on){
	change(y,len);
	for(int h=2;h<=len;h<<=1){
		Complex wn(cos(2*PI/h),sin(on * 2*PI/h));
		for(int j=0;j<len;j+=h){
			Complex w(1,0);
			for(int k=j;k<j+h/2;k++){
				Complex u = y[k];
				Complex t = w*y[k+h/2];
				y[k] = u+t;
				y[k+h/2] = u-t;
				w = w*wn;
			}
		}
	}
	if(on==-1){
		for(int i=0;i<len;i++){
			y[i].x /= len;
		}
	}
}

const int N = 3e6 + 5;
Complex A[N];
Complex B[N];
int ans[N];
signed main(){
	string s;
	cin >> s;
	int n = s.length();
	int len = 1;
	while(len <= n*2)len*=2;
	for(int i=0;i<n;i++){
		if(s[i] == 'B'){
			B[i].x = 1;
		}else{
			A[n-1-i].x = 1;
		}
	}
	
	fft(A,len,1);
	fft(B,len,1);
	for(int i=0;i<len;i++){
		A[i] = A[i]*B[i];
	}
	fft(A,len,-1);
	for(int i=0;i<len;i++){
		ans[i] = (int)(A[len-1-i].x+0.5);
	}
	
	for(int i=len -n+1;i<len;i++){
		cout << ans[i] << endl;
	}cout << endl;

}