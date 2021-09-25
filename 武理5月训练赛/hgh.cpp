#include<bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 10)
#define clr(arr, val) memset(arr, val, sizeof(arr))
#define pb push_back
#define sz(a) ((int)(a).size())

const int mod = 1e18;
int qp(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans*=a;
		a*=a;
		b>>=1;
	}
	return ans;
};
int a[1000000];
int b[1000000];
string s;
signed main() {
	int t;
	int c = 0;
	scanf("%d", &t);
	while (t--) {

		int n=0;
		int cnt = 0;

		cin>>s;
		int l = s.length();
		for(int i=1; i<2*s.length(); i++)a[i]=0,b[i]=0;


		for(int i=0; i<l; i++) {
			a[i]=s[i]-'0';
			//cout<<a[i];
		}//cout<<endl;
		//h = 1000;
		for(int i=0; i<l-1; i++) {
			b[i]=a[l-i-2];
		}
	//	for(int i=0;i<l-1;i++)cout<<b[i];cout<<endl;
		for(int i=0; i<l-1; i++) {
			if(b[i]>1) {
				b[i+1]+=b[i]/2;
				b[i]=b[i]%2;
			}
			if(b[i]==1&&i%2==1) {
				b[i+1]+=1;
			}
		}
		int u = l-2;
		while(b[u]) {
			b[u+1]+=b[u]/2;
			b[u]=b[u]%2;
			u++;
		}
		int po = 0;
		for(int i=u;i>0;i--){
			if(b[i]==0&&po==0);
				else{
					po=1;cout<<b[i];
				}
		}
		if(s[l-1]=='1'&&b[0]==0)cout<<1<<endl;else if(s[l-1]=='1'&&b[0]==1){cout<<"01"<<endl;
		}
		else cout<<0<<endl;
	}
	return 0;
}
