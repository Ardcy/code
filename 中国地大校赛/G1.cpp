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

int a[3000];




string jieya(string s){
	string ans = "";
	int l = s.length();
	int cnt = 0;
	int  p = l;
	int p1 = -1;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){	
		}
		else if(s[i]=='['){
		}
		else if(s[i]==']'){
		}
		else{
			ans+=s[i];		
		}
		if(s[i]>='0'&&s[i]<='9'){	
			cnt=s[i]-'0';
			int sl = 1;
			p1 = i;
			//cout<<i+2<<endl;
			for(int j=i+2;j<l;j++){
				
				if(s[j]==']')sl--;
				if(s[j]=='[')sl++;
				//cout<<"sl="<<sl<<endl;
				
				if(sl==0){
					p=j;break;
				}
				
			}
			if(p!=l)break;
		}
	}
	//cout<<cnt<<endl;
	//cout<<p<<" "<<p1<<endl;
	string s1 = "";
	if(p1!=-1) s1 = jieya(s.substr(p1+2,p-p1-2));
	//cout<<p1+2<<" "<<p-p1-2<<endl;
	for(int i=1;i<=cnt;i++){
		ans+=s1;
	}
	//cout<<ans<<endl;
	if(p==l)return ans;else
	return ans+jieya(s.substr(p,l-p));
	
}
signed main(){
    string s;
	while(cin>>s){
		//cout<<s<<endl;
    	cout<<jieya(s)<<endl;
	}
	return 0;
}


