#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
int a[126];
int b[126];
int ans[50][126];
signed main(){
	string s,t;
	cin>>s>>t;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(ans,0,sizeof(ans));
	int ls = s.length(),lt=t.length();
	for(int i=0;i<ls;i++){
		a[s[i]-'A']++;
	}
	for(int i=0;i<lt;i++){
		b[t[i]-'A']++;
	}
	for(int i=0;i<126;i++){
		ans[1][i]=a[i];
		ans[2][i]=b[i];
	}
	for(int i=3;i<=40;i++){
		for(int j=0;j<126;j++){
			ans[i][j]=ans[i-1][j]+ans[i-2][j];
		}
	}
	int n;
	cin>>n;
	for(int i=0;i<126;i++){
		//cout<<a[i]<<endl;
		if(ans[n][i]){
			//cout<<(char)('a'+i)<<": "<<ans[n][i]<<endl;
			printf("%c: %lld\n",'A'+i,ans[n][i]);
		}
	}
	return 0;
}


