#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5, M =35;
int nxt[N][M],dp[M];
char s1[N],s2[M];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%s%s",s1+1,s2+1);
		n = strlen(s1+1);
		m = strlen(s2+1);
		for(int i=0;i<26;i++)nxt[n+1][i] = n+1;
		for(int i=n;i;i--){
			for(int j=0;j<26;j++){
				if(j==s1[i]-'a'){
					nxt[i][j] = i;
				}else{
					nxt[i][j] = nxt[i+1][j];
				}
			}
		}
		int q;
		scanf("%d",&q);
		while(q--){
			int l,r;
			scanf("%d%d",&l,&r);
			dp[0] = l-1;
			for(int i=1;i<=m;i++){
				dp[i] = n+1;
			}
			int lcs = 0;
			for(int i=1;i<=m;i++){
				for(int j=i-1;~j;j--){
					if(dp[j]<r&&nxt[dp[j]+1][s2[i]-'a']<=r){
						dp[j+1] = min(dp[j+1],nxt[dp[j]+1][s2[i]-'a']);
					}
					if(dp[j+1]<=r)lcs = max(lcs,j+1);
				}
			}
			printf("%d\n",r-l+1+m-2*lcs);
		}
	}
}