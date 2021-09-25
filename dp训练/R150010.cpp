#include<bits/stdc++.h>
using namespace std;
#define int long long
int hor[700][700];
int ver[700][700];
char s[700][700];
signed main(){
	int h,w;
	cin>>h>>w;
	for(int i=0;i<h;i++)cin>>s[i];
	for(int i=0;i<=h;i++){
		for(int j=0;j<=w;j++){
			if(i==0||j==0){
				ver[i][j]=0;
			}
			else{
				ver[i][j]=ver[i-1][j]+ver[i][j-1]-ver[i-1][j-1];
				if(i<h&&s[i-1][j-1]=='.'&&s[i][j-1]=='.')
				{
					ver[i][j]++;
				}
			}
			if(i==0||j==0){
				hor[i][j]=0;
			}else{
				hor[i][j]=hor[i-1][j]+hor[i][j-1]-hor[i-1][j-1];
				if(j<w&&s[i-1][j-1]=='.'&&s[i-1][j]=='.'){
					hor[i][j]++;
				}
			}
		}
	}
	int t;
	cin>>t;
	while(t--){
		int xb,yb,xa,ya;
		cin>>xb>>yb>>xa>>ya;
		int ans = 0;
		ans += hor[xa][ya-1]-hor[xb-1][ya-1]-hor[xa][yb-1]+hor[xb-1][yb-1];
		ans += ver[xa-1][ya]-ver[xa-1][yb-1]-ver[xb-1][ya]+ver[xb-1][yb-1];
		cout<<ans<<endl;
	}
	return 0;
}
