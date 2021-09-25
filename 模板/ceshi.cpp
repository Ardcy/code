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
const int MAXN = 165536;
int arr[MAXN];
int sum[70000];
int pnum[70000];

Complex A[65536];
Complex B[65536];
int read(){int x;scanf("%d",&x);return x;}

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		arr[i] = read();
	}		
	
	int k = 1024;
	long long int ans = 0;
	for(int i=0;i<n;i+=k){
		memset(sum,0,sizeof(sum));
		memset(pnum,0,sizeof(pnum));
		int l = i ,r = min(i+k-1,n-1); 
		for(int j=l+2;j<=r;j++)sum[arr[l]+arr[j]]++;
		for(int j=l+1;j<r;j++){
			ans += sum[2*arr[j]];
			for(int w = l;w<j;w++){
				sum[arr[w]+arr[j+1]]--;
			}
			for(int w = j+2;w<=r;w++){
				sum[arr[w]+arr[j]]++;
			}
		}
	}
	 // cout << ans << endl;
	for(int i=0;i<n;i+=k){
		memset(pnum,0,sizeof(pnum));
		int l = i ,r = min(i+k-1,n-1);
		for(int i=0;i<l;i++){
			pnum[arr[i]]++;
		}
		for(int j=l;j<=r;j++){
			for(int w=j+1;w<=r;w++){
				ans += pnum[min(30001,max(0,2*arr[j]-arr[w]))];
			}	
		}
		memset(pnum,0,sizeof(pnum));
		for(int j=r+1;j<n;j++){
			pnum[arr[j]]++;
		}
		for(int j=l;j<=r;j++){
			for(int w = j+1;w<=r;w++){
				ans += pnum[min(30001,max(0,2*arr[w]-arr[j]))];
			}
		}
	}
	for(int i=0;i<n;i+=k){
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		int l = i ,r = min(i+k-1,n-1);
		for(int j=0;j<l;j++){
			A[arr[j]].x+=1;
		}
		for(int j=r+1;j<n;j++){
			B[arr[j]].x+=1;
		}
		fft(A,65536,1);
		fft(B,65536,1);
		for(int j=0;j<65536;j++){
			A[j] = A[j]*B[j];
		}
		fft(A,65536,-1);
		for(int j=l;j<=r;j++){
			ans += (long long int)(A[arr[j]*2].x+0.5);
		}
	}
	cout << ans << endl;
}
