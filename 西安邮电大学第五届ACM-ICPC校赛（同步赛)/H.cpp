#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX

#define pb push_back
const int mod = 998244353;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;}return ans;};

int H[1050000];
int maxn = 1050000;
signed main(){
    ios::sync_with_stdio(false);
    std::cin.tie(0);
	for(int i=1;i<=maxn;i++){
		for(int j=i*i,cnt=i;j<=maxn;j+=i,cnt++){
			H[j]=(i+cnt)/2;
		}
	}
	for(int i=1;i<=maxn;i++){
		H[i]=H[i-1]+H[i];
	}
	
    int T;
    cin>>T;
    while(T--){
		int x;
		cin>>x;
		cout<<H[x]<<endl;
    }
    

    return 0;
}


