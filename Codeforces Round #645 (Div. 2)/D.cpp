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

int d[405000];
int num[405000];
int cnum[405000];
int ra = 0,rb = 0;

int x,n;
int f1 = 0;

void find(int la,int lb){	
	int now = num[la-1]+lb;
	int pred = now+x-1;
	int f = lower_bound(num+1,num+2*n+1,pred)-num; 
	ra = f;
	rb = pred - num[ra-1]; 
}
int la1 = 0, lb1 = 0;
void find1(int la,int lb){	
	int now = num[la-1]+lb;
	int pred = now-x+1;
	int f = lower_bound(num+1,num+2*n+1,pred)-num; 
	ra = f;
	rb = pred - num[ra-1];
	 
}
int sum(int a,int b,int c,int d){
	
	int p = cnum[c-1]-cnum[a-1];
	p+=(d+1)*d/2;
	p-=(b-1)*b/2;
	return p;
}
signed main(){
	
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		cin>>d[i];
	}
	for(int i=n+1;i<=2*n;i++)d[i]=d[i-n];
	d[2*n+1]=1e14;
	for(int i=1;i<=2*n;i++){
		num[i]=num[i-1]+d[i];
		cnum[i]=cnum[i-1]+(1+d[i])*d[i]/2;
	}
	
	int la = 1,lb = 1;
	int ans = 0;
	while(ra<=2*n){
		
		find(la,lb);
		int ans1 = sum(la,lb,ra,rb);
		ans=max(ans,ans1);

		if(lb==d[la]||rb==d[ra]){
			la+=1;lb=1;
		}else if(lb<=rb&&d[la]-lb<=d[ra]-rb){
			lb = d[la];
		}else if(d[la]-lb<=d[ra]-rb){
			
			lb += d[ra]-rb;
		}else{
			lb=d[la];
		}
		
	}
	for(int i=1;i<=2*n;i++){
		find1(i,d[i]);
		if(rb>0){
			ans=max(ans,sum(ra,rb,i,d[i]));
		}
	}
	cout<<ans<<endl;
	return 0;
}


