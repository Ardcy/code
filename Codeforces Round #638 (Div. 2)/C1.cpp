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
		string ans = "";
		int cnt = 0;
		for(int i=0; i<26; i++)if(a[i])cnt++;
		if(cnt==1) {
			for(int i=0; i<26; i++) {
				if(a[i]) {
					for(int j=1; j<=(k-1+a[i])/k; j++)
						ans+=char('a'+i);
				}
			}
			cout<<ans<<endl;
		} else {
			int f = 1;
			for(int i=0; i<26; i++) {
				if(a[i]!=k&&a[i]!=0)f=0;
			}
			if(f&&cnt==2) {
				//cout<<1<<endl;

				for(int i=0; i<26; i++) {
					for(int j=1; j<=a[i]/k; j++)cout<<char(i+'a');
				}
				cout<<endl;

			} else {
				for(int i=0; i<26; i++) {
					if(a[i]) {


						if(a[i]<k) {

							int num = a[i];
							for(int j=i+1; j<26; j++) {
								if(a[j]) {
									num+=a[j];
									if(num>=k) {
										cout<<char('a'+j)<<endl;
										i=27;
										break;
									}

								}
							}
						} else {

							if(cnt==2&&a[i]==k) {
								for(int i=0; i<26; i++) {
									for(int j=1; j<=(a[i]+k-1)/k; j++)cout<<char(i+'a');
								}
								cout<<endl;
								
								i=27;break;
							}
							a[i]-=(k-1);
							for(int j=i; j<26; j++) {
								for(int h=1; h<=a[j]; h++)cout<<char('a'+j);
							}
							cout<<endl;
							i=27;
							break;
						}
					}
				}


			}

		}

	}
	return 0;
}


