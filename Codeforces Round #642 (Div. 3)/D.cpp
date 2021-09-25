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

int a[205000];
int dep[205000];
struct node{
	int x,y,z;
}e[205000];
int cnt = 0;
void digui(int  left,int right){
	
	int mid = (left+right)/2;
	e[mid].x=left;e[mid].y=right-left+1;e[mid].z=mid;
	if(mid>left)digui(left,mid-1);
	if(mid<right)digui(mid+1,right);
}
bool cmp(node a,node b){
	if(a.y==b.y )return a.x<b.x;
	else{
		return a.y>b.y;
	}
}

signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		
			for(int i=1;i<=n;i++)a[i]=0;
			 digui(1ll,n);
			sort(e+1,e+n,cmp);
			for(int i=1;i<=n;i++)dep[e[i].z]=i;
			for(int i=1;i<=n;i++)cout<<dep[i]<<" ";cout<<endl;
		
	}
	return 0;
}


