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
int c[105000];
int d[105000];
vector<int>P[105000];
int tree[1000000];
int n1 = 1000000;
void add(int k, int num)
{
	while (k <= n1) {
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
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		c[i-1]=b[i];
		d[i-1]=a[i];
	}
	sort(c,c+n);
	sort(d,d+n);
	//for(int i=0;i<n;i++)cout<<c[i]<<" ";cout<<endl;
	int l = unique(d,d+n)-d;
	int s = unique(c,c+n)-c;
	for(int i=1;i<=n;i++){
		b[i]=lower_bound(c,c+s,b[i])-c+1;
		a[i]=lower_bound(d,d+l,a[i])-d+1;
	}
	for(int i=1;i<=n;i++){
		int f = query(b[i]-1);
		for(int p:P[a[i]]){
			if(p<b[i])f--;
		}
		cout<<f<<" ";
		add(b[i],1);
		P[a[i]].pb(b[i]);
	}cout<<endl;
	return 0;
}


