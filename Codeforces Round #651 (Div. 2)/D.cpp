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


int k,n,d[500100],f[500100][20];//f[i][j]是从第i个数起，到第2^j个数止的，最小值 



int l = 1;
int r;

int cnt = 0;

struct node{
	int a1,b1,c1;
};
bool operator <(const node& A,const node& B){
	return A.c1<B.c1;
}
priority_queue<node> Q;

signed main(){
	
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>d[i];
	//RMQ预处理
	r = n;
	for(int i=1;i<=n;i++)f[i][0]=d[i];
	for(int j=1;j<=17;j++)
		for(int i=1;i<=n;i++)
			f[i][j]=min(f[i][j-1],f[i+ (1<< (j-1) ) ][j-1]);
	k/=2;
	
	
	
	
	int x;int y;
	while(k--){
		cin>>x>>y;
		int z=0;
		while(1<<(z+1)<=y-x+1)z++;
		printf("%d ",min(f[x][z],f[y-(1<<z)+1][z]));
		//这里的两个数字：x和y-(1<<z)+1的意思是：
		//从x之后的2^z个数字   和   从y之前的2^z个数。 
	}
	return 0;
}


