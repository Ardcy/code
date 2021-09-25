#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
int qp(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod;
		b>>=1;
	}
	return ans;
};

int jie[120];
const int maxn = 120;
long long s2[maxn][maxn];//存放第二类Stirling数
void init()

{

	s2[1][1]=1;

	for(int i=2; i<maxn; i++)

		for(int j=1; j<maxn; j++)

			s2[i][j]=(s2[i-1][j-1]+j*s2[i-1][j])%mod;

}

int j(int a,int b) {
	int ans=1;
	for(int i=1; i<=b; i++) {
		ans*=(a-i+1);
		ans%=mod;
	}
	return ans;
}
int e_gcd(int a,int b,int &x,int &y) {
	if(b==0) {
		x=1;
		y=0;
		return a;
	}
	int gcd=e_gcd(b,a%b,y,x);
	y-=a/b*x;
	return gcd;
}
int inv(int a,int n) {
	int x,y;
	e_gcd(a,n,x,y);
	return (x+n)%n;
}
int c(int a,int b) {
	
	int ans = 1;
	ans*=(j(a,b)%mod);
	ans*=inv(j(b,b)%mod,mod);
	ans%=mod;
	return ans;
}
const int MOD=mod;
void mul(int f[2] ,int a[2][2]) {
	int c[2];
	memset(c,0,sizeof(c));
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++)
			c[i]=(c[i]+(long long)f[j]*a[j][i])%MOD;
	memcpy(f,c,sizeof(c));
}
void mulself(int a[2][2]) {
	int c[2][2];
	memset(c,0,sizeof(c));
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++)
			for(int k=0; k<2; k++)
				c[i][j]=(c[i][j]+(long long)a[i][k]*a[k][j])%MOD;
	memcpy(a,c,sizeof(c));
}
int F[400];
	int f[2]= {0,1};
	int a[2][2]= {{0,1},{1,1}};
int ff(int n){
	f[0]=0;f[1]=1;
	a[0][0]=0;
	a[0][1]=1;
	a[1][0]=1;
	a[1][1]=1;
	//a[2][2]= {{0,1},{1,1}};
	while(n) {
		if(n&1) mul(f,a);
		mulself(a);
		n>>=1;
	}
	return (f[0]%mod);
} 
signed main() {
	//for(int i=1;i<120;i++)s2[i][0]=1,s2[0][i]=1;
	int n,m;
	cin>>n>>m;
	init();
	jie[0]=1;
	int ans1 = 0,ans2 = 0,ans3 = 0;
	for(int i=1; i<=100; i++) {
		jie[i]=jie[i-1]*i%mod;
		jie[i]%=mod;
	}
	F[1]=1;
	F[2]=1;
	F[3]=2;
	for(int i=4;i<=300;i++)
	F[i]=(F[i-1]+F[i-2])%mod,F[i]%=mod;
	for(int i=1; i<=m; i++) {
		for(int j=0; j<=i; j++) {
			if(j%2==0)ans1+=((s2[m][i]*jie[i]%mod)*c(n+1,i-j)%mod)*ff(n+2*j+2);
			else {
				ans1-=((s2[m][i]*jie[i]%mod)*c(n+1,i-j)%mod)*ff(n+2*j+2);
			}
			ans1 = (ans1%mod)+mod;
			ans1%=mod;	
		}
		if(i%2) {
			ans3+=(s2[m][i]*jie[i]%mod)*F[2*i+1];
			
		} else {
			ans3-=(s2[m][i]*jie[i]%mod)*F[2*i+1];
		}
		ans3 = (ans3%mod)+mod;
		ans3%=mod;
		//	cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
	}
//	ans2=ans1;
	//cout<<ans4<<" "<<ans5<<endl; 
	//cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
	int ans =ans1+ans3;
	ans%=mod;
	ans+=mod;
	ans%=mod;
	cout<<ans<<endl;
	return 0;
}



