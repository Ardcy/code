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

int a[405000];
	
queue<int>P,Q;
signed main(){
	int t;
	cin>>t;
	string s;
	while(t--){
		int n;
		cin>>n;
		cin>>s;
	    while(!P.empty())P.pop();
		while(!Q.empty())Q.pop();
		
		for(int i=0;i<n;i++)a[i]=0;
		int f1 = 0, f2 = 0;
		
		for(int i=0;i<n;i++){
			int r = s[i]-'0';
			if(r==1){
				if(!Q.empty()){
					int u = Q.front();
					Q.pop();
					a[i]=a[u];
					P.push(i);
					f1 = max(a[i],f1);
				}else{
					a[i]=f1+1;
					f1++;
					P.push(i);
				}
			}else{
				if(!P.empty()){
					int u = P.front();P.pop();
					a[i]=a[u];
					Q.push(i);
					f1 = max(a[i],f1);
				}else{
					a[i]=f1+1;
					f1++;
					Q.push(i);
				}
			}
		}
		cout<<max(f1,f2)<<endl;
		for(int i=0;i<n;i++)printf("%lld ",a[i]);cout<<endl;
	}
	return 0;
}


