//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//const int mod = 1e9+7;
//int a[105000];
//int qp(int a,int b){
//	int ans = 1;
//	while(b){
//		if(b&1)ans*=a,ans%=mod;
//		a*=a;a%=mod;
//		b>>=1;
//	}
//	return ans;
//}
//signed main(){
//	int x,n;
//	cin>>n>>x;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	}
//	int mi = 0,sum = 0;
//	for(int i=1;i<=n;i++)mi=max(mi,a[i]),sum+=a[i];
//	int np = 0;
//	for(int i=1;i<=n;i++)if(mi==a[i])np++;
//	//cout<<np<<endl;
//	//cout<<qp(x,sum-mi)<<endl;
//	
//	cout<<__gcd(np,x)*qp(x,mi)%mod<<endl;
//	return 0;
//}


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int kMod = 1e9+7;
#define int long long
int n,x;
int a[105000];
map<ll,int>cnt;
#define fi first
#define se second
int qp(int a,int b) {
	int ans = 1;
	while(b){
		if(b&1)ans*=a,ans%=kMod;
		a*=a,a%=kMod;
		b>>=1;
	}
	return ans;
} 
signed main(){
	cin>>n>>x;
	ll sum = 0;
	for(int i=0;i<n;i++){
		cin>>a[i];sum+=a[i];
	}
	for(int i=0;i<n;++i)cnt[sum-a[i]]++;
	for(map<ll,int>::iterator it = cnt.begin();it!=cnt.end();){
		ll p = it->fi;
		int q = it->se;
		if(q>=x){
			cnt[p]%=x;
			if(cnt[p]==0)cnt.erase(p);
			cnt[p+1]+=q/x;
			it=cnt.lower_bound(p+1);
		}else{
			++it;
		}
	}
	ll tmp = cnt.begin()->first;
	tmp = min(tmp,sum);
	cout<<(qp(x,tmp%(kMod-1)))<<endl;
}




















