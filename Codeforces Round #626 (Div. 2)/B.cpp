#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl
#define int long long
int a[2000];
int b[1000];
signed main(){
	string s;
	cin>>s;
	int y = 1;
	int cntl = 0,cntr = 0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='(')cntl=1;
		if(cntl&&s[i]==')'){
			y=0;
		}
	}
	if(y==1){
		cout<<0<<endl;
		return 0;
	}
	int cnt=0;
	while(1){
		cnt++;
		int j = s.length();
		for(int i=0;i<j;i++){
			if(s[i]=='('&&a[i]==0){
				for(j=j-1;j>i;j--){
					if(s[j]==')'&&a[j]==0){
						a[i]=cnt;
						a[j]=cnt;
						b[cnt]++;
						break;
					}
				}				
			}	
		}
		int flag = 1;
		cntl = 0,cntr = 0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='('&&a[i]==0)cntl=1;
			if(cntl&&a[i]==0&&s[i]==')'){
					flag = 0;
			}
		}
		if(flag==0)continue;
		else break;
	}
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++){
		cout<<b[i]*2<<endl;
		for(int j=0;j<s.length();j++){
			if(a[j]==cnt)cout<<j+1<<" ";
		}
		cout<<endl;
	}
	
}
