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

int a[105000];
int b[105000];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)a[i]=0;
		for(int i=1,u;i<=n;i++){
			cin>>u;
			a[u]++;
		}
		int num1 = 0,num2 = 0;
		sort(a+1,a+n+1,cmp);
		num1 = a[1];
		for(int i=1;i<=n;i++)if(a[i]==num1)num2++;
//		cout<<n<<endl;
//		cout<<num1<<endl;
//		cout<<num2<<endl;
		
		cout<<(n-num2)/(num1-1)-1<<endl;
	}
	return 0;
}


