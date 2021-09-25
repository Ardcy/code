#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=300500;
const int mod = 1e9+7;
int n,a[maxn+10],hg[maxn+10];
int sum[4*maxn+10][3];
void build(int k,int l,int r)
{
    if(l==r)
    {
        sum[k][0]=a[l];
        sum[k][1]=hg[l];
        return;
    }
    int mid=l+r>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    sum[k][0]=(sum[k<<1][0]+sum[k<<1|1][0])%mod;
	sum[k][1]=(sum[k<<1][1]+sum[k<<1|1][1])%mod;
}
void change(int k,int l,int r,int x,int v)
{
    if(r<x||l>x) return;
    if(l==r&&l==x)
    {
        sum[k][0]+=v;
        sum[k][0]%=mod;
        sum[k][1]=1-sum[k][1];
        sum[k][1]%=mod;
        return;
    }
    int mid=l+r>>1;
    change(k<<1,l,mid,x,v);
    change(k<<1|1,mid+1,r,x,v);
    sum[k][0]=(sum[k<<1][0]+sum[k<<1|1][0])%mod;
    sum[k][1]=(sum[k<<1][1]+sum[k<<1|1][1])%mod;
}
int query(int k,int l,int r,int x,int y)
{
    if(y<l||x>r) return 0;
    if(l>=x&&r<=y) return sum[k][0];
    int mid=l+r>>1;
    int res;
    res=query(k<<1,l,mid,x,y);
    res+=query(k<<1|1,mid+1,r,x,y);
    res%=mod;
    return res;
}
int query2(int k,int l,int r,int x,int y)
{
    if(y<l||x>r) return 0;
    if(l>=x&&r<=y) return sum[k][1];
    int mid=l+r>>1;
    int res;
    res=query2(k<<1,l,mid,x,y);
    res+=query2(k<<1|1,mid+1,r,x,y);
    res%=mod;
    return res;
}
#define N 205000
char a1[N];
int dp[N];

signed main()
{
	cin>>n;
	cin>>a1;
   int pre = -1;
     for(int i=0;i<N;i++){
   		if(a1[i]=='1'){
   			a[i+1]=i+1;
   			hg[i+1]=1;
   			pre = i;
   			break;
		}	
   }
   if(pre==-1){
   		cout<<0;
	    return 0;
   }
   int cnt = 0;
   int ans = 0;
   
   for(int i=pre+1;i<n;i++){
   		if(a1[i]=='1'){
   			cnt++;
   			dp[i] = cnt*(i-pre) + dp[pre];
			dp[i] %=mod;
   			ans+=dp[i];
   			ans%=mod;
			pre=i;	
		}	
    }
   cout<<ans<<endl;
   
    int t; 
   	cin>>t;
   	int ua,ub;
   	build(1,1,n);
    for(int yt=1;yt<=t;yt++)
    {
    	cin>>ua>>ub;
      	int le,ri,numl,numr;
		if(ua==1){
      		le = query(1,1,n,1,ub-1);
      		ri = query(1,1,n,ub+1,n);
      		numl = query2(1,1,n,1,ub-1);
      		numr = query2(1,1,n,ub+1,n);
      		change(1,1,n,ub,ub);
      		ans += (numl*ub-le)+(ri-numr*ub);
      		ans%=mod;
      		
		}
		if(ua==2){
			change(1,1,n,ub,-ub);
      		le = query(1,1,n,1,ub-1);
      		ri = query(1,1,n,ub+1,n);
      		numl = query2(1,1,n,1,ub-1);
      		numr = query2(1,1,n,ub+1,n);
      		ans -= (numl*ub-le)+(ri-numr*ub);
      		ans = (10000 * mod+ans)%mod;
		}
	//	cout<<le<<" "<<ri<<" "<<numl<<" "<<numr<<" "<<ans<<endl;
      cout<<ans<<endl;  
    }
    return 0;
}

