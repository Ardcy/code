#include<bits/stdc++.h>
using namespace std;
#define int long long
int b[205000][3];
char f1[205000];
signed main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	b[0][0]=1;b[0][1]=1;b[0][2]=1;
	if(s[0]=='R')b[0][0]--;
	if(s[0]=='B')b[0][1]--;
	if(s[0]=='G')b[0][2]--;
	for(int i=1;i<s.length();i++){
		b[i][0]=min(b[i-1][1],b[i-1][2])+1;
		b[i][1]=min(b[i-1][0],b[i-1][2])+1;
		b[i][2]=min(b[i-1][1],b[i-1][0])+1;
		if(s[i]=='R')b[i][0]--;
		if(s[i]=='B')b[i][1]--;
		if(s[i]=='G')b[i][2]--;	
	}
	int u=3;n--;
	if(b[n][0]<b[n][1])u=0;else u=1;
	if(b[n][u]<b[n][2])u=u;else u=2;
	cout<<b[n][u]<<endl;	
	for(int i=n;i>=1;i--){
		if(u==0)f1[i]='R';
		if(u==1)f1[i]='B';
		if(u==2)f1[i]='G';
		if(b[i-1][(u+1)%3]<b[i-1][(u+2)%3])u=(u+1)%3;else u=(u+2)%3;
	}
	if(u==0)f1[0]='R';if(u==1)f1[0]='B';if(u==2)f1[0]='G';
	cout<<f1<<endl;
	return 0;
}
