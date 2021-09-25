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
signed main(){
    string s;
	while(cin>>s){
    	
    	for(int i=1;i<=200;i++)a[i]=0;
    	int sl = 0,sr = 0;
    	int l = s.length();
    	int cnt = 0;
    	for(int i=0;i<l;i++){
    		
    		if(s[i]>='0'&&s[i]<='9'){
    			
				a[sl+1]= s[i]-'0';
				
			}
    		else if(s[i]=='['){
    			sl++;
    			
    			
			}
			else if(s[i]==']'){
    			sr++;
    			
			}
			else{
				
				
				
			}
    		
		}
    	
	}
	return 0;
}


