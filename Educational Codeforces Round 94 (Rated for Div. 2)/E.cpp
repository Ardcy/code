#include<bits/stdc++.h>
#define pii pair<int,int>
#define x first
#define y second 
#define ll long long
using namespace std;
const int N=3e3+5;
int a[N];
int cnt[N][N];
int main(){
    int T=read();
	for(;T;--T){
		int n=read();
        for(int i=1;i<=n;++i)a[i]=read();
		for(int i=1;i<=n;++i) 
		 for(int j=1;j<=n;++j)cnt[i][j]=0;
		ll ans=0;
		for (int j=n;j>=1;--j) {
         for (int i=1;i<j;++i)
          ans+=cnt[a[i]][a[j]];
        for (int l=j+1;l<=n;l++)
         cnt[a[j]][a[l]]++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
	

