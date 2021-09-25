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
const int maxn=1100;
int a[maxn][maxn];
 
void init()
{
    for(int i=1;i<=1000;i++)
        a[0][i]=1,a[i][1]=1;
    for(int i=1;i<maxn;i++)
        for(int j=2;j<=maxn;j++)
            if(j<=i)
                a[i][j]=(a[i][j-1]+a[i-j][j])%mod;
            else
                a[i][j]=a[i][i]%mod;
                
}

signed main(){
	int n,m;
	cin>>n>>m;
	int p1 = 0;
	for(int i=1;i<=sqrt(m);i++){
		if(m%(i*i)==0)p1=i;	
	}
	init();
	cout<<a[p1][n]%mod<<endl;
	return 0;
}


