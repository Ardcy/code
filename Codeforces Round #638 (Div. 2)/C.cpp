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

int a[26];
signed main() {
	
//	string u = "ui";
	///cout<<(u+"")<<endl;
	int t;
	cin>>t;
	string s;
	while(t--) {
		int n,k,ff=0;
		cin>>n>>k;
		cin>>s;
		for(int i=0; i<26; i++)a[i]=0;
		int l = s.length();
		for(int i=0; i<l; i++) {
			a[s[i]-'a']++;
		}
		string ans="";
		int u = 0;
		for(int i=0; i<=25; i++) {
			if(a[i]==0&&u==0) {
				continue;
			} else if(a[i]==0&&u)continue;
			else {
				u++;
				if(u==1&&a[i]<k) {
					for(int j=i+1; j<=25; j++) {
						if(a[j]) {
							cout<<char('a'+j)<<endl;
							ff=1;	i=26;
							break;
						
						}
					}
				}

				if(a[i]%k==0) {
					for(int j=1; j<=a[i]/k; j++)ans+=char('a'+i);
				} else {
					for(int j=i+1; j<=25; j++) {
						if(a[j]) {
							ans+=('a'+j);
							cout<<ans<<endl;
							ff=1;i=26;
							break;
							
						}
					}
				}

			}

		}
		if(ff)continue;
		else{
			cout<<ans<<endl;
		}
	}
	return 0;
}


