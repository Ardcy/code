#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105000][26];
int h[26];
int c[26][26];
signed main(){
	string s;
	cin>>s;
	for(int i=1;i<=s.length();i++){
		for(int j=0;j<26;j++){
			a[i][j]=a[i-1][j];
		}
		a[i][s[i-1]-'a']++;
		h[s[i-1]-'a']++;
	}
	int l = s.length();
	for(int i=1;i<=s.length();i++){
		for(int j=0;j<26;j++){
			c[s[i-1]-'a'][j]+=(a[l][j]-a[i][j]);
		}
	}
	int ans=0;
	for(int i=0;i<26;i++)ans=max(ans,h[i]);
	for(int i=0;i<26;i++)for(int j=0;j<26;j++)ans=max(ans,c[i][j]);
	cout<<ans<<endl;
	return 0;
}
