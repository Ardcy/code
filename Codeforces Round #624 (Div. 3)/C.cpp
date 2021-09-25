#include<bits/stdc++.h>
using namespace std;
#define int long long
#define de(x) cerr<<#x<<"="<<x<<endl
void solve(){
	
}
int a[205000];
int b[26];
signed main(){
	int t,n,m;
	cin>>t;
	string s;
	while(t--){
		memset(b,0,sizeof(b));
		cin>>n>>m;
		cin>>s;
		for(int i=1;i<=m;i++){
			cin>>a[i];
		}
		sort(a+1,a+m+1);
		for(int i=0;i<s.length();i++){
			
			int g=i+1;
			int pos1=m+1-(lower_bound(a+1,a+m+1,g)-a);
			b[s[i]-'a']+=pos1+1;
		}
		for(int i=0;i<=24;i++)cout<<b[i]<<" ";
		cout<<b[25]<<endl;
	}	
} 
