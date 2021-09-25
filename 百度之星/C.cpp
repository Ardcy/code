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

int a[2000][2000];

int b[2000][2000];


int gcd(int a1,int b1){
    return b1?gcd(b1,a1%b1):a1;
}
signed main(){
	
	

//	
//	for(int i=2;i<=1005;i++){
//		for(int j=i;j<=1005;j++){
//			if(b[i][j]==0&&__gcd(i,j)!=1){
//				for(int z=j;z<=1000;z+=j)b[i][z]=1;
//			} 	
//		}
//	}
//		
	for(int i=1;i<=1005;i++){
		for(int j=i;j<=1005;j++){
			
			a[i][j]=max(a[i-1][j],a[i][j-1]);
			//if(b[i][j]==0)a[i][j]+=1;
			if(gcd(i,j)==1)a[i][j]+=1;
		}
	}

	
	int t;
	cin>>t;
	while(t--){
		int u,v;
		cin>>u>>v;
		if(u>v)swap(u,v);
		cout<<a[u][v]<<endl;\
	}
	return 0;
}


