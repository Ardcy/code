#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
const int maxn = 1e6 +10;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);
const double eps = 1e-6;

template<class T>
inline void read(T &res);

void yes(){cout<<"YES"<<endl;}
void no(){cout<<"NO"<<endl;}


int c[maxn]; 
int n;
int Lowbit(int x)  // 2^k
{
	return x&(-x);
}
void update(int i, int x)//i点增量为x
{
	while(i <= n)
	{
		c[i] += x;
		i += Lowbit(i);
	}
}
int sum(int x)//区间求和 [1,x]
{
	int sum=0;
	while(x>0)
	{
		sum+=c[x];
		x-=Lowbit(x);
	}
	return sum;

}

signed main(){

    ios::sync_with_stdio(false);
    std::cin.tie(0);

    int k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        update(t,1);
    }
    for(int i=1;i<=k;i++){
        int t;
        cin>>t;
        if(t<0){
            t = -t;
            int l = 1,r=n;
            while(l<=r){
                int mid = (l+r)>>1;
                int k = sum(mid);
                if(k<t) l=mid+1;
                else r = mid-1;
            }
            update(l,-1);        
        }
        else{
            update(t,1);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(sum(i)!=0){
            ans=1;
            cout<<i<<endl;
            break;
        }
    }
    if(!ans) cout<<ans<<endl;
    return 0;
}


template<class T>
inline void read(T &res)
{
    char c;
    T flag=1;
    while((c=getchar())<'0'||c>'9')
        if(c=='-')flag=-1;res=c-'0';
    while((c=getchar())>='0'&&c<='9')
        res=res*10+c-'0';res*=flag;
}
