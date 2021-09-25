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
int a[2000];
int b[2000];
signed main(){
	int t;

	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int f1=1;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=1024;i++){
			
			for(int j=1;j<=n;j++){
				b[j]=(i^a[j]);
				//if(i==1)cout<<b[j]<<" ";
			}
			//if(i==1)cout<<endl;
			sort(b+1,b+n+1);
			int f = 1;
			for(int j=1;j<=n;j++){
				if(b[j]!=a[j]){
					f=0;break;
				}			
			}
			if(f==1){
				cout<<i<<endl;
				f1=0;
				break;
			}
			
		}
		if(f1==1)cout<<-1<<endl;
		
		
		
	}
	return 0;
}


