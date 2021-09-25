#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%mod;a*=a,a%=mod;b>>=1;}return ans;};
int c[205000];
int ck[205000];
int b[205000];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	int t=1;

	while(t--){
		int n,k;
		cin>>n>>k;
		int u;
		for(int i=1;i<=k;i++)c[i]=0;
		for(int i=1;i<=n;i++){
			cin>>u;
			c[u]++;
			b[i]=u;
		}
		for(int i=1;i<=k;i++)
		{
			cin>>u;
			ck[i]=u;
		}
//		
//		cout<<"--------"<<endl;
//		
//		for(int i=1;i<=k;i++)cout<<c[k]<<endl;
//		cout<<"--------"<<endl;
		int ans = 0;
		int num = 0;
		for(int i=k;i>=1;i--){
			
			num+=c[i];
			ans = max(ans,num/ck[i]);
		//	cout<<num<<" "<<c
		//	cout<<"ans="<<ans<<endl;
			
		}
		cout<<ans<<endl;
		
//		cout<<"-------"<<endl;
//		cout<<n<<endl;
//		
//		cout<<"-------"<<endl;
		sort(b+1,b+n+1,cmp);
		for(int i=1;i<=n;i++)cout<<b[i]<<endl;
		int h = n%ans;
	//	cout<<"h="<<h<<endl;
	//	cout<<(n/ans+1)<<endl;
		for(int i=1;i<=ans;i++){
			if(i>h)cout<<n/ans<<" ";
			else cout<<(n/ans+1)<<" ";
			for(int t=i;t<=n;t+=ans){
				
				//cout<<"t= "<<t<<endl;
				cout<<b[t]<<" ";
			}
			cout<<endl;
			
		}
		
	}
	return 0;
}


