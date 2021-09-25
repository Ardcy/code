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

vector<int >P[205000];

stack<pair<int,int>>F;
int val[205000];
int ans[205000];
void dfs(int a){
	for(auto p:P[a]){
		ans[p]=max(val[p],ans[a]+val[p]);
		cout<<p<<" "<<a<<" "<<ans[p]<<endl;
	}
	for(auto p:P[a])dfs(p);
}
signed main(){
	string s;
	cin>>s;
	int now = 1;
	int p = 0;
	int cnt = 1;
	int k = 0;
	int g = 0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='(')g=1;
	}
	if(!g){cout<<s<<endl;return 0;}
    for(int i=0;i<s.length();i++){
    	if(s[i]=='-')now=-1;
    	if(s[i]>='0'&&s[i]<='9')p=p*10+(s[i]-'0'),k=1;
		if(s[i]=='('){  
			val[cnt]=now*p;
			if(F.size()!=0){
				int y = F.top().first;	
				P[y].pb(cnt);	
			//	cout<<y<<" "<<cnt<<endl;
			}
			F.push(mp(cnt,now*p));
			cnt++;p=0;now=1;
		}
		if(s[i]==','&&k==1){
			//F.pop();
			val[cnt]=now*p;
			int y = F.top().first;	
			P[y].pb(cnt);	
			//cout<<y<<" "<<cnt<<endl;
			cnt++;p=0;now=1;k=0;
		}
		if(s[i]==')'&&k==1){
			int y = F.top().first;
			val[cnt]=now*p;	
			P[y].pb(cnt);	
		//	cout<<y<<" "<<cnt<<endl;
		//	cout<<"top.fi="<<F.top().first<<endl;
			F.pop();
			//cout<<"top.fi="<<F.top().first<<endl;
			cnt++;p=0;now=1;k=0;
		}
		else if(s[i]==')'&&k==0){
			//cout<<"top.fi="<<F.top().first<<endl;
			F.pop();
		}
	}
	
	for(int i=1;i<=105000;i++)ans[i]=-100000000000;
	//cout<<val[1]<<endl;
	dfs(1);
	int ans1=0;
	for(int i=1;i<=cnt;i++){
		ans1=max(ans1,ans[i]);
	//	for(auto p:P[i])cout<<p<<" ";cout<<endl;
	}
	cout<<ans1<<endl;
	return 0;
}
/* -1(-1(1(0(3,-5),0(0,0(0,0))),0(1,1)),2)*/

