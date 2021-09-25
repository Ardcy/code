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

int a[1005000];
signed main() {
	int t;
	cin>>t;
	string s;
	while(t--) {
		int n,k;
		cin>>n>>k;
		cin>>s;
		vector<int>P[k];
		int l = s.length();
		int cnt = 0;
		for(int i=0; i<l; i++) {
			if(s[i]=='1')cnt++,P[(i+1)%k].pb(1ll);
			else P[(i+1)%k].pb(0ll);
		}
		//if(cnt==0){cout<<0<<endl;continue;}
		int ans = mod;
		for(int i=0; i<k; i++) {
			//	cout<<"i="<<i<<endl;


			int l = 0;
			int r = P[i].size()-1;
			int si = P[i].size();
			int cnt1=0;
			for(int j=0; j<si; j++) {
				if(P[i][j]==1)cnt1++;
				//cout<<P[i][j];cout<<" ";
				//	if(suml<=0)l=j;
			}	//cout<<endl;
			int suml=0,sumr=0;
//			int f1=0;
//			for(int j=0; j<si; j++) {
//				if(P[i][j]==1)f1=1;
//				if(f1) {
//
//
//					if(P[i][j]==1&&suml<=0)l=j;
//					suml+=P[i][j];
//					if(P[i][j]==0)suml-=1;
//					//if(suml==1)l=j;
//					//cout<<suml<<endl;
//				}
//			}
			//int cnt2 = 0;
			for(int j=0; j<=si-1; j++) {
					sumr-=P[i][j];
					if(P[i][j]==0)sumr+=1;
					sumr=min(sumr,0ll);
					ans=min(ans,cnt+sumr);
			}
//			cout<<l<<" -------- "<<r<<endl;
//			//	cout<<cnt<<endl;
//			if(r<l)swap(r,l);
//			if(r==l&&f==1)ans=min(ans,cnt-1);
//			else if(r==l&&f==0)ans=min(ans,cnt);
//			else if(r<l)ans=min(ans,cnt);
//			else {
//
//				int ans1=0;
//				for(int j=0; j<si; j++) {
//					if(j<l||j>r)ans1+=P[i][j];
//					else ans1+=(1-P[i][j]);
//				}
//
//				ans=min(ans,ans1+cnt-cnt1);
//				//cout<<"ans1="<<ans1<<endl;
//			}


		}
		cout<<ans<<endl;

	}
	return 0;
}


