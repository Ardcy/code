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
int num1,num2,num3;
int solve(){
	if(num1>=1&&num3>=2){
		cout<<"YES"<<endl;
	}
	else if(num2>=1&&num3>=3){
		cout<<"YES"<<endl;
	}
	else if(num2>=2){
		cout<<"YES"<<endl;
	}
	else cout<<"NO"<<endl;
}
signed main(){
	int n;
	cin>>n;
	int u;
	for(int i=1;i<=n;i++){
		cin>>u,a[u]++;
		if(a[u]==6)	num1++;
		if(a[u]==4) num2++;
		if(a[u]==2) num3++;
	}
	char c;
	int q;
	cin>>q;getchar();
	for(int i=1;i<=q;i++){
		scanf("%c %lld",&c,&u);	
		cout<<c<<endl;
		if(c=='+'){
			a[u]++;
			if(a[u]==6)	num1++;
		    if(a[u]==4) num2++;
			if(a[u]==2) num3++;
		}else{
			if(a[u]==6)	num1--;
		    if(a[u]==4) num2--;
			if(a[u]==2) num3--;
			a[u]--;
		}
	 //	cout<<a[1]<<" "<<a[2]<<endl;
	//	cout<<num1<<" "<<num2<<" "<<num3<<endl;
		solve();
		getchar();
	}
	return 0;
}


