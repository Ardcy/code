#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int arr[N];
int a[N];
int b[N];
int c[N];
const int   mod = 1e9+7;

int qp(int a,int  b){
    int  ans = 1;
    if(b){
        if(b&1)ans*=a,ans%=mod;
        a*=a,a%=mod;
        b>>=1;
    }
    return ans;
}
//
//int qp(int a,int b){
//	int ans = 1;
//	while(b){
//		if(b&1)ans*=a,ans%=mod;
//		a*=a,a%=mod;
//		b>>=1;
//	}
//	return ans;
//}
int Answerforcn(long long n) {
    // write code here
    if(n==1)return 14;
    if(n==2)return 210;
    else{
    	cout<<"9999999"<<endl;
        int ans = qp(15ll,n-2);
        return 14ll*ans%mod;
    }
}
signed main(){
	int n;
	cout<<qp(2ll,3ll)<<endl;
	
	cout<<Answerforcn(10)<<endl;  
	a[1] = 2;
	a[2] = 6;
	b[1] = 7;
	b[2] = 35;
	
	for(int i=3;i<=20;i++){
		a[i] = 2*a[i-1]+3*a[i-2];
		b[i] = 3*b[i-1] + 10 * b[i-2];
	}
	for(int i=1;i<=20;i++){
		cout<<a[i]*b[i]<<endl;
	}
}
