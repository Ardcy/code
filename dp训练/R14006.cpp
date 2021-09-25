#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005];
int mod  = 1e9+7;
signed main(){
	a[0]=0;
	a[1]=1;
	a[2]=2;
	for(int i=3;i<=100000;i++)a[i]=(a[i-1]+a[i-2])%mod;
	
	string s;
	cin>>s;
	s+="1";
	int ans=1;
	int flag=1;
	if(s[0]=='m'||s[0]=='w')flag=0;
	for(int i=1;i<s.length();i++){
	
		int cnt = 0;
		if(s[i]==s[i-1]&&(s[i]=='u'||s[i]=='n'))cnt=1;
		while(s[i]==s[i-1]&&(s[i]=='u')){
			cnt++;
			i++;	
		}
		if(cnt)ans*=a[cnt];
		cnt=0;
		if(s[i]==s[i-1]&&(s[i]=='u'||s[i]=='n'))cnt=1;
		ans%=mod;
		while(s[i]==s[i-1]&&(s[i]=='n')){
			cnt++;
			i++;	
		}
		if(cnt)ans*=a[cnt];
		ans%=mod;
		if(s[i]=='m'||s[i]=='w')flag=0;
	}
	if(flag==0){
		cout<<0<<endl;
		return 0;	
	} 
	else if(ans==0)cout<<1<<endl;
	else cout<<ans<<endl;
	return 0;
}
