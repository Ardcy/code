#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 10005,mod = 998244353;
int fac[N],rev[N];
int n,m,res;
int qp(int a,int b){int ans = 1;while(b){if(b&1)ans=ans*a%mod;a=a*a%mod;b>>=1;}return ans;}
int inv[N];
void init(int n){
	fac[0]=1;rev[n]=1;
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	rev[n]=qp(fac[n],mod-2);
	for(int i=n-1;i>=0;i--)rev[i]=rev[i+1]*(i+1)%mod;
}
int A[N],B[N];

signed main(){
	
	init(10002);
	inv[0]=0;
	for(int i=1;i<N;i++){
		inv[i]=(rev[i]*fac[i-1]%mod)%mod;
	}

//	cout<<inv[2]<<endl;
	int t;
	cin>>t;
	while(t--){
		int m,p,q;
		cin>>m>>p>>q;
		
//		
//		int a1 = inv[p]*100%mod*m%mod;
//		a1 += mod-1;
//		a1%=mod;
//		a1=a1*q*inv[100]%mod;
//		cout<<(m-a1+mod)%mod<<endl;
//		
//		
		cout<<((m-q*m*inv[p]+q*inv[100]+mod)%mod+mod)%mod<<endl;
//		int a1 = p*q*inv[100]%mod*inv[100]%mod;
//		int a2 =  inv[10000-(100-p)*q]*10000%mod;
//		int a3 = (mod+1-a2)%mod;
//		int a4 = qp(a1,m);
//		cout<<a4<<endl;
//		cout<<(2*mod+m-a4-a3)%mod<<endl;
//		
//		int a1 = (100*p*m-100*q-q*p*(m-2))%mod;
//		//cout<<a1<<endl;
//		a1 = (a1+mod)%mod;
//		int a2 = 100*p;
//		cout<<(a1*inv[a2]%mod)<<endl;
	}
	
}
