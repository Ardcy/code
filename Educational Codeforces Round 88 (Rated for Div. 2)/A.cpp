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


signed main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		
		int num = n/k;
		
		if(m>num){
			m-=num;
			n=(m+k-2)/(k-1);
			cout<<num-n<<endl;
			
		}else{
			cout<<m<<endl;
		}
		
	}
	return 0;
}


