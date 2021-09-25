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

int a[1050];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		
		int lef = 0, rig = n+1;
		
		int suml = 0, sumr = 0;
		
		int prel = 0, prer = 0;
		int cnt = 0;
		while(lef<rig){
			
			sumr+=prer;
			while(prel<=prer&&lef<rig){
				prel+=a[++lef];
				//cout<<prel<<endl;
					if(lef==rig-1)break;
			}
			prer = 0;
			cnt++;
			
			if(lef==rig-1)break;
			
			while(prer<=prel&&lef<rig){
				prer+=a[--rig];
				//cout<<prer<<endl;
					if(lef==rig-1)break;
			}
			suml+=prel;
			prel = 0;
			cnt++;
			//cout<<lef<<" "<<rig<<endl;
			if(lef==rig-1)break;
		}
		cout<<cnt<<" "<<suml+prel<<" "<<sumr+prer<<endl;
		
	}
	return 0;
}


