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

int c[20];

int p[5];







signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		for(int i=0;i<=9;i++)c[i]=0;
		for(int i=1;i<=n;i++)
		cin>>s,c[s[4]-'0']++;
		sort(c,c+10);
		int sum=0; 
		int ans = 0;
		for(int i=0;i<=9;i++)sum+=c[i];
		int cn = 0;
		
		for(int i=sum/5;i<=c[9];i++){
			
			if(check(i)){
				cout<<i<<endl;
				break;
			}
		}
		
	}
	
	
	return 0;
}


