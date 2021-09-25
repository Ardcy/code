#include<bits/stdc++.h>
using namespace std;
int a[27];
int main(){
	int n,m;
	char c;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=m;i++)
	{
		cin>>c;
		a[c-'a']=1;
	}
	int cnt = 0,ans = 0;
	for(int i=0;i<=s.length()-1;i++){
		if(a[s[i]-'a']==1)cnt++;
		else{
			ans+=(1+cnt)*cnt/2;
			cnt = 0;
		}
	}
	cout<<ans<<endl;
}
