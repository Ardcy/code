#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
#define int long long
string s;
int a[200][26];
signed main(){
	int n;
	cin>>n;
	cin>>s;
	cout<<s<<endl;
	int cnt = 0;
	if(s[0]=='a')a[0][1]=1;
	else if(s[0]=='z')a[0][24]=1;
	else a[0][s[0]-'a'+1]=a[0][s[0]-'a'-1]=1;
	
	for(int i=0;i<=s.length()-2;i++){
		
		if(s[1+i]=='a'&&a[i][1]==1){
			for(int j=0;j<26;j++){
				a[i+1][j]=a[i][j];
			}
			a[i+1][1]=1;
			cnt++;	
		}
		else if(s[i+1]=='z'&&a[i][24]==1){
			for(int j=0;j<26;j++){
				a[i+1][j]=a[i][j];
			}
			a[i+1][24]=1;
			cnt++;	
		}
		else if(a[i][s[i+1]-'a'+1]==1||a[i][s[i+1]-'a'-1]==1){
			
			for(int j=0;j<26;j++){
				a[i+1][j]=a[i][j];
			}
			a[i+1][s[i+1]-'a'+1]=1;
			a[i+1][s[i+1]-'a'-1]=1;	
				cnt++;			
		}
			if(s[i+1]=='a')a[i+1][1]=1;
			else if(s[i+1]=='z')a[i+1][24]=1;
			else a[i+1][s[i+1]-'a'+1]=a[i+1][s[i+1]-'a'-1]=1;
			
	
	}
	cout<<cnt<<endl;
	return 0;
}
