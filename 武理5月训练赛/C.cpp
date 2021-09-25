#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 1e9+7;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;}return ans;};

int a[105000];
int tree[1000000];
int n = 1000000;
void add(int k, int num)
{
	while (k <= n) {
		tree[k] += num;
		k += k & (-k);
	}
}
int query(int k)
{
	int sum = 0;
	while (k) {
		sum += tree[k];
		k -= k & (-k);
	}
	return sum;
}

signed main(){
	int n;
	cin>>n;
	int u;
	int y = 0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
		int b = query(a[i]-1);
		y+=(i-1-b)%2;
		add(a[i],1);
		y%=2;
	}
	int ans = 1;
	for(int i=1;i<n;i++){
		ans*=qp(i,n-i);
		ans%=mod;
	}
	if(y==0)cout<<ans<<endl;else{
		cout<<(-ans)<<endl;
	}
	return 0;
}


