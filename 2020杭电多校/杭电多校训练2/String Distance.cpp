#include<bits/stdc++.h>
using namespace std;
int read(){
	int q;
	scanf("%d",&q);
	return q;
}
const int N = 2e5+5;
int nxt[N][27];
int dp[27];
signed main(){
	int t;
	t = read();
	while(t--){
		string s,s2;
		cin >> s >> s2;
		int n = s.length();
		for(int i=1;i<=26;i++){
			nxt[n][i] = n;
		}

		for(int i=n-1;i>=0;i--){
			for(int j=26;j>=1;j--){
				if(s[i]-'a'==j-1){
					nxt[i][j] = i;
				}else{
					nxt[i][j] = nxt[i+1][j];
				}
			}
		}
		int q;
		q = read();
		while(q--){
			int l,r;
			l = read(),r = read();
			l--;r--;
			int m = s2.length();
			for(int i=1;i<=26;i++){
				dp[i] = n+1;
			}
			dp[0] = l-1;
			int lcs = 0;
			for(int k=1;k<=m;k++){
				for(int j=k-1;j>=0;j--){
					if(dp[j]<r&&nxt[dp[j]+1][s2[k-1]-'a'+1] <= r){
						dp[j+1] = min(dp[j+1],nxt[dp[j]+1][s2[k-1]-'a'+1]);
						lcs = max(j+1,lcs);
					}
				}
			}
			cout << r-l+1+m-2*lcs << endl;
		}
	}
}