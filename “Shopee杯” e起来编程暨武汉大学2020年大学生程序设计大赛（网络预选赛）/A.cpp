#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
int dp[30][30];
signed main(){
	int n;
	cin>>n;
	string s; 
	int ans = 0;
	for(int i=1;i<=n;i++){
		cin>>s;
		int l=s.length();
		if((s[0]-'a')==(s[l-1]-'a')){
			for(int j=0;j<26;j++)if(dp[j][s[l-1]-'a'])dp[j][s[l-1]-'a']+=l;
			if(!dp[(s[0]-'a')][(s[0]-'a')])dp[(s[0]-'a')][(s[0]-'a')]=l;
		} 
		else{
			for(int j=0;j<26;j++){
				if(dp[j][s[0]-'a'])dp[j][s[l-1]-'a']=max(dp[j][s[0]-'a']+l,dp[j][s[l-1]-'a']);
			}
			if(dp[s[0]-'a'][s[l-1]-'a']==0)dp[s[0]-'a'][s[l-1]-'a']=l;
		}
	}
	for(int i=0;i<26;i++){
		ans=max(ans,dp[i][i]);
		//cout<<dp[i][i]<<endl;	
	}
	cout<<ans<<endl;
	return 0;
}

