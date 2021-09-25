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
		int n,m;
		cin>>n>>m;
		int mid = qp(2,m-1);
		map<int,int>II;
		vector<int>P;
		for(int i=1;i<=n;i++){
			int f = 0;	
			getchar();
			for(int j=1;j<=m;j++){
				if(getchar()=='0'){
					f=f*2+0;
				}else{
					f=f*2+1;
				}
			}
			P.pb(f);
		}
		sort(P.begin(),P.end());
		int l = P.size();
		int cnt = 0;
		for(auto p:P){
			II[p]=1;
			if(p==0)mid--;
		}
		//int cnt = 0;
		for(auto p:P){
			cnt++;
			if(p<mid&&cnt%2==0){
				while(II[mid]!=0){
					mid++;
				}
			}
			if(p>mid&&cnt%2==0){
				
			}
			if(p<=mid&&cnt%2==1){
			}
			if(p>mid&&cnt%2==1){
				while(II[mid]!=0){
					mid--;
				}
			}			
		}
		cout<<mid<<endl; 
		
	}
	return 0;
}


