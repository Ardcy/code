#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
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
mt19937 mrand(random_device{}());
const int mod = 1000000007;
int rnd(int x){return mrand()%x;}
int pb(int a,int b) {int res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a*=a;a%=mod;}return res;}
int a[205000][26];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		for(int i=0;i<k;i++)for(int j=0;j<=25;j++)a[i][j]=0;
//		if((n/k)%2==0){
//			for(int i=0;i<s.length();i++){
//				a[i%k][s[i]-'a']++;
//			}	
//		}
//		else{
			
			for(int i=0;i<s.length();i++){	
				a[min(i%k,k-1-i%k)][s[i]-'a']++;
			}
//		}
		
//		if((n/k)%2==0){
//			int sum1 = 0;
//			for(int i=0;i<k;i++){
//				int sum = 0;
//				int m = 0;
//				for(int j=0;j<=25;j++){
//					if(a[i][j]>m)m=a[i][j];
//					sum+=a[i][j];
//				}
//				sum1+=sum-m;
//			}
//			cout<<sum1<<endl;
//		}
//		else{
			int sum1 = 0;
			if(k%2==1)
			for(int i=0;i<=k/2;i++){
				int sum = 0;
				int m = 0;
				for(int j=0;j<=25;j++){
					if(a[i][j]>m)m=a[i][j];
					sum+=a[i][j];
				}
				sum1+=sum-m;
			}
			else{
				for(int i=0;i<k/2;i++){
					int sum = 0;
					int m = 0;
					for(int j=0;j<=25;j++){
						if(a[i][j]>m)m=a[i][j];
						sum+=a[i][j];
					}
					sum1+=sum-m;
				}
			}
			cout<<sum1<<endl;
	//	}
	}

	return 0;
}
