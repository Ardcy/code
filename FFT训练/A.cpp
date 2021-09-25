
#include<bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
struct Complex
{
    double r,i;
    Complex(double _r = 0,double _i = 0)
    {
        r = _r; i = _i;
    }
    Complex operator +(const Complex &b)
    {
        return Complex(r+b.r,i+b.i);
    }
    Complex operator -(const Complex &b)
    {
        return Complex(r-b.r,i-b.i);
    }
    Complex operator *(const Complex &b)
    {
        return Complex(r*b.r-i*b.i,r*b.i+i*b.r);
    }
};
void change(Complex y[],int len)
{
    int i,j,k;
    for(i = 1, j = len/2;i < len-1;i++)
    {
        if(i < j)swap(y[i],y[j]);
        k = len/2;
        while( j >= k)
        {
            j -= k;
            k /= 2;
        }
        if(j < k)j += k;
    }
}
void fft(Complex y[],int len,int on)
{
    change(y,len);
    for(int h = 2;h <= len;h <<= 1)
    {
        Complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j = 0;j < len;j += h)
        {
            Complex w(1,0);
            for(int k = j;k < j+h/2;k++)
            {
                Complex u = y[k];
                Complex t = w*y[k+h/2];
                y[k] = u+t;
                y[k+h/2] = u-t;
                w = w*wn;
            }
        }
    }
    if(on == -1)
        for(int i = 0;i < len;i++)
            y[i].r /= len;
}

const int MAXN = 600020;
Complex x[MAXN];
int arr[MAXN];

long long num[MAXN];

signed main(){

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		memset(num,0,sizeof(num));
		for(int i=0;i<n;i++){cin >> arr[i];num[arr[i]]++;}
		sort(arr,arr+n);
		int len = 1;
		while(len <= arr[n-1]*2)len *=2;
		for(int i=0;i<=len;i++){
			x[i] = {0,0};
			
		}
		for(int i=0;i<=len;i++){
			x[i].r = num[i];
		}
		fft(x,len,1);
		for(int i=0;i<len;i++){
			x[i]=x[i]*x[i];
		}
		fft(x,len,-1);
		for(int i=0;i<len;i++){
			num[i] = (long long)(x[i].r+0.5);
			//cout << (int)x[i].x << " " ;
		}//cout << endl;
		for(int i=0;i<n;i++){
			num[arr[i]*2]-=1;
		}
		for(int i=0;i<=len;i++){
			num[i]/=2;
		}
		num[0] =0;
		for(int i=1;i<=len;i++){
			num[i] = num[i] + num[i-1];
		}
		long long int cnt = 0;
	
		for(int i=0;i<n;i++){
			cnt += num[len] - num[arr[i]];
			cnt -= n-1;
			cnt -= (long long)(n-i-1) * i;
			cnt -= (long long)(n-i-1)*(n-i-2)/2; 
		}
		long long int tot =(long long)n*(n-1)*(n-2)/6;
		printf("%.7f\n",(double)cnt/tot);

	}

}
