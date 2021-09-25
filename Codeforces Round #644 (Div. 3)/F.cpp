#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
int qp(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod;
		b>>=1;
	}
	return ans;
};

string s[11];
signed main() {
	int t;
	cin>>t;
	while(t--) {
		int n,m;
		cin>>n>>m;

		for(int i=1; i<=n; i++) {
			cin>>s[i];
		}
		if(n==1||m==1) {
			cout<<s[1]<<endl;
			continue;
		}

		string ans;
		string ans1="";
		for(int i=0; i<n; i++) {
			for(int y=1; y<=n; y++) {
				ans="";
				for(int j=0; j<i; j++)ans+=s[1][j];
				ans+=s[y][i];
				for(int j=i+1; j<m; j++)ans+=s[1][j];

			//	cout<<"ans="<<ans<<endl;
				int ff = 1;
				for(int p=1; p<=n; p++) {
					int cnt = 0;
					for(int q=0; q<m; q++) {
						if(ans[q]!=s[p][q])cnt++;
					}
					if(cnt>1)ff=0;
				}
				if(ff){
					ans1="";
					ans1=ans;
				}
			}


		}
		
		if(ans1.length()>0)
		{
			cout<<ans1<<endl;
			continue;
		}else{
			cout<<-1<<endl;
		}


	}
	return 0;
}


