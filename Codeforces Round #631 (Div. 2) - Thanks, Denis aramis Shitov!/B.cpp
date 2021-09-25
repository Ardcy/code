#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define int long long
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef double db;
const int mod = 1000000007;
int pb(int a,int b) {int res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a*=a;a%=mod;}return res;}
int a[205000];
int b[205000];
int c[205000];

signed main(){
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int mi = 0;
		for(int i=1;i<=n;i++)b[i]=0,c[i]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			mi = max(mi,a[i]);
			b[a[i]]++;
		}
		int f = 1;
		for(int i=1;i<=n-mi;i++){
			if(b[i]!=2)f=0;
		}
		for(int i=n-mi+1;i<=mi;i++){
			if(b[i]!=1)f=0;
		}
		if(f==0){
			cout<<0<<endl;continue;
		}
		int q1 = n-mi;
		int q2 = mi;
		int cnt = 0;
		set<int>pe;
		int max1=0,max2=0;
		for(int i=1;i<=q1;i++){
			pe.insert(a[i]);
			max1=max(max1,a[i]);
		}
		int f1=0,f2=0;
		if(pe.size()==q1&&max1==q1){
			f1=1;
			cnt++;
		}
		if(f1==1&&cnt==1&&mi==n-mi){
			cout<<1<<endl;
			cout<<mi<<" "<<mi<<endl;
			continue;
		}
		set<int>pee;
		for(int i=1;i<=mi;i++)
			pee.insert(a[i]),max2=max(max2,a[i]);
		if(pee.size()==mi&&max2==mi){
			f2=1;
			cnt++;
		}
		cout<<cnt<<endl;
		if(cnt==2){
			if(f1)cout<<q1<<" "<<q2<<endl;
			if(f2)cout<<q2<<" "<<q1<<endl;
		}
		if(cnt==1){
			if(f1)cout<<q1<<" "<<q2<<endl;
			if(f2)cout<<q2<<" "<<q1<<endl;
		}
	}
	return 0;
}
