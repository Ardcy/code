#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define int long long
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef double db;
const int mod = 1000000007;
int qp(int a,int b) {int res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a*=a;a%=mod;}return res;}
int b[4000];
int c[4000];
int d[3050000];
signed main(){
	int n,k;
	cin>>n>>k;
	string s;cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]=='L')b[i+1]=1;
		else b[i+1]=2;
	}
	int cnt = 0,cnt1=0;
	int sum=0;
	int y = 0;
	while(1){
		cnt=0;
		for(int i=1;i<n;i++){
			if(b[i]==2&&b[i+1]==1){
				b[i]=1,b[i+1]=2;
				d[++y]=i;
				i++;
				cnt++;
			}
		}
		c[++cnt1]=cnt;
		
		sum+=cnt;
		if(cnt==0){
			cnt1--;
			break;	
		}
	}
	if(sum<k||sum==0){
		cout<<-1<<endl;
	}else{
		
		int cnt2=1;
		int r=0;
		int w=0;
		cout<<sum<<" "<<cnt1<<endl;
		for(int i=1;i<=cnt1;i++)cout<<c[i]<<endl;
		for(int i=1;i<=k;i++){
			cout<<"i="<<i<<" cnt2="<<cnt2<<endl;
			int l = 0;
			if(sum-i!=cnt1-cnt2){
				l=1;
				r++;
			}
			else l=c[cnt2]-r,cnt2++,r=0;
			cout<<l;
			for(int i=1;i<=l;i++){
				cout<<" "<<d[++w];
			}cout<<endl;
			if(r==c[cnt2])cnt2++,r=0;
		}
	}
	return 0;
}
