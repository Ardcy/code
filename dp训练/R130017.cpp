#include<bits/stdc++.h>
using namespace std;
int a[2000][2000];
int b[2000][2000];
int c[2000][2000];
int d[2000];
int e[2000];
int main(){
	int n,m;
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			b[i][j]=b[i][j-1]+a[i][j];
		}
		for(int j=m;j>=1;j--){
			c[i][j]=c[i][j+1]+a[i][j];
		}
		for(int j=1;j<=m;j++){
			if(!a[i][j])ans+=(b[i][j-1]>0)+(c[i][j+1]>0);
		}	
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			d[j]=d[j-1]+a[j][i];
		}
		for(int j=n;j>=1;j--){
			e[j]=e[j+1]+a[j][i];
		}
		for(int j=1;j<=n;j++){
			if(a[j][i]==0)ans+=(d[j-1]>0)+(e[j+1]>0);
//			cout<<j<<" "<<i<<" "<<ans<<endl;
		}
	}
	cout<<ans<<endl; 
	
}
