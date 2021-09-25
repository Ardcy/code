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

int a[10100];
int sum[10500];

signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i],sum[i]=0;
		for(int i=1;i<=n;i++){
		int sum1 = a[i];
		
		for(int j=i+1;j<=n;j++){
			if(sum1+a[j]<=n){
				sum[sum1+a[j]]=1;
				sum1+=a[j];
			}
			else{break;
			}
		}
	}
	int cnt = 0;
	for(int i=1;i<=n;i++){
		if(sum[a[i]])cnt++;
	}
	cout<<cnt<<endl;
	}
	return 0;
}


