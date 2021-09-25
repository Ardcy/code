#include<bits/stdc++.h>
using namespace std;
#define int1 unsigned long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;}return ans;};

int1 g(int1 x){
	x^=x<<13;
    x^=x>>7;
    x^=x<<17;
    return x;
}
unordered_map<int ,int >mp1;
//const int hashmod=4000007;
//struct HAsh{
//    int head[hashmod],next[500005];
//    int S[500005];
//    int tot;
//    int added[500005];
//    int adtot;
//    void add(int s){
//        int tmp=s%hashmod;
//        if(head[tmp]==0)added[++adtot]=tmp;
//        ++tot;
//        S[tot]=s;
//        next[tot]=head[tmp];head[tmp]=tot;
//    }
//    int que(int s){
//        for (int i=head[s%hashmod];i;i=next[i])if(S[i]==s)return 1;
//        return 0;
//    }
//    void cl(){
//        for (int i=1;i<=adtot;i++)head[added[i]]=0;
//        adtot=0;
//        tot=0;
//    }
//}H1;

signed main(){
	int n,t;
	cin>>n>>t;
	int1 s;
	// n = 1e6;
	cin>>s;
	for(int i=1;i<=t;i++){
	//	cout<<s<<endl;
	//if(H1.que(s))cout<<"111111"<<endl;
	int1 s1;
	cin>>s1;
		for(int j=1;j<=4;j++){
		//	H1.add(s1%(1<<16));	
			mp1[s1%(1<<16)]=i;
			s1>>=16;
		
		}
		//s=g(s);
		//cout<<bitset<64>(s)<<endl;
		
	}
	cout<<"------"<<endl;
	int ans = 0;
	cout<<s<<endl;
	for(int i=0;i<n;i++){
		
			int1 s1=s;
			int cnt = 0;
			int k;
		for(int j=1;j<=4;j++){
			//if(H1.que(s1%(1<<16)))cnt++;
			if(mp1[s1%(1ll<<16)])cnt++,k=mp1[s1%(1ll<<16)];
			s1>>=16;
		}
		cout<<k<<endl;
		
		if(cnt>=1){
			ans+=qp(2,k-1);
			ans%=mod;		
		//	cout<<i<<endl;
		}
		s=g(s);
		//cout<<i<<endl;
	}
	cout<<ans<<endl;
	return 0;
}


