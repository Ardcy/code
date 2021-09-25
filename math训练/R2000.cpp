#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct ans{
	int i,a,b;
}A[100005];
int n,m,x,y,ma[N][N],r[N],c[N];
signed main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		cin>>x>>y;
		ma[x][y]=1;
		r[x]++;c[y]++;
	}
	for(;n;n--){
		for(int i=1;i<n;i++){
			if(c[i]==0){
				A[m++]=(ans){2,n,i};
				for(int j=1;j<=n;j++)swap(ma[j][n],ma[j][i]);
				swap(c[i],c[n]);break;
			}
			for(int i=1;i<=n;i++)if(ma[n][i])c[i]--;
		}
		printf("%d\n",m);
		for(int i=0;i<m;i++)printf("%d %d %d\n",A[i].i,A[i].a,A[i].b);
	}
	return 0;
}
