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
const int N = 10010000;
int cnt=0, n1=10010000;
int prime[N];
bool on[N];
int init()
{
	on[0] = on[1] = 1;
	for(int i = 2; i <= n1; ++i){
		if(!on[i])	prime[++cnt] = i;
		for(int j = 1; j <= cnt && i * prime[j] <= n1; ++j){
			on[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
			
		}		
	}
}
int a[505000];
int b[505000][2];
signed main(){
	init();
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int f = a[i];
		int p1 = -1, p2 = -1;
		for(int j=1;j<=N;j++){
			if(a[i]%prime[j]==0){
				p1=prime[j];
				break;
			}
		}
		if(p1!=-1)while(a[i]!=1&&a[i]%p1==0){
			a[i]/=p1;
		}
		if(a[i]==0){
			b[i][0]=-1;b[i][1]=-1;continue;
		}
		
		if(!on[a[i]])p2=a[i];else{
//		    for(int j=2;j<=sqrt(a[i]);j++){
//		     	if((a[i]%j==0)&&(!on[j]))p2=j;
//		    }	
//		    
		    for(int j=1;j<=N&&prime[j]<=a[i];j++){
			    if(a[i]%prime[j]==0){
				    p2=prime[j];
				   if(__gcd(p1+p2,f)==1)break;
			    }
			}
		}
//		if(p2!=-1)while(f%(p1+p2)==0){
//			p2+=p1;
//			if(p2>f)break;
//		}
		if(p2>f)p2=-1;
		if(p1!=-1&&p2!=-1&&(__gcd(p1+p2,f)==1)&&(f%p1==0)&&(f%p2==0)){
			b[i][0]=p1;b[i][1]=p2;
		}else {
			b[i][0]=-1;b[i][1]=-1;
		}
	///	cout<<i<<" "<<p1<<" "<<p2<<endl;
	}
	for(int i=1;i<=n;i++){
		cout<<b[i][0]<<" ";
	}cout<<endl;
	for(int i=1;i<=n;i++){
		cout<<b[i][1]<<" ";
	}cout<<endl;
}


