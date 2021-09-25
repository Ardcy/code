#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;}return ans;};

void w1(){
	cout<<"Ashishgup"<<endl;
}
void w2(){
	cout<<"FastestFinger"<<endl;
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==1){
			w2();
		}
		else if(n==2){
			w1();
		}else if(n%2==1){
			w1();
		}else{
			int f1 = 0;
			while(n%2==0){
				n/=2;
				f1++;
			}
			
			int f = 0;
			
			for(int i=3;i<=sqrt(n);i+=2){
				if(n==(i*(n/i)))f=1;
			}
			if(f1>1&&n!=1)w1();else if(f)w1();else w2();
			
//			for(int i=2;i<=40;i++){
//				if((1<<i)==n)f=0;
//			}
//			if(n%2==0&&n/2%2==1)w2();
//			else if(f)w1();
//			else w2();
		}
	}
	return 0;
}


