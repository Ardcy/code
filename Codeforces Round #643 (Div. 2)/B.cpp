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

int a[205000];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		int r = n+1;
		int cnt = 0;
		int p = 0;int p1 = 0, p2 = 0;
		
		for(int i=1;i<=n;i++){
			if(p==0){
				p = a[i];
				p1 = 0;
				p2 = a[i];
				p1++;
				p2 = max(p2,a[i]);
				if(p2<=p1){
					cnt++;p=0;
				} 
			}else{
				p1++;
				p2 = max(p2,a[i]);
				if(p2<=p1){
					cnt++;p=0;
				} 

			}
			
		//	cout<<cnt<<endl;
		}
		cout<<cnt<<endl;
	}
	return 0;
}


