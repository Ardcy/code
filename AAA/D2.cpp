#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
int qp(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod;
		b>>=1;
	}
	return ans;
};
const int N = 1e6+5;
int bit[N];
int lowbit(int  a) {
	return a&(-a);
}
void updata(int index) {
	while(index<N) {
		bit[index]++;
		index+=lowbit(index);
	}
}
void del(int index) {
	while(index<N) {
		bit[index]--;
		index+=lowbit(index);
	}
}
int query(int index) {
	int ans = 0;
	while(index>0) {
		ans+=bit[index];
		index-=lowbit(index);
	}
	return ans;
}


signed main() {
	int n,m,t;
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>t,updata(t);
	for(int i=1; i<=m; i++) {
		cin>>t;
		if(t>0)updata(t);
		else {
			
			cout<<1<<endl;
			t=-t;
			int l = 1,r=n;
			int ans = 0;
			int mid;
			while(l<=n) {
				mid=(l+r)>>1;
				//cout<<mid<<endl;
				if(query(mid)>=t) {
					ans=mid;
					r=mid-1;
				} else {
					l=mid+1;
				}
				//cout<<l<<" "<<r<<endl;
				if(l>r)break;
			}
			cout<<ans<<"-----"<<endl;
			del(ans);
		}
	}
	
	for(int i=1;i<=n;i++){
		if(query(i)>0){
			return 0*printf("%lld\n",i);
		}
	}
	cout<<0<<endl;
	return 0;
}


