#include<bits/stdc++.h>
using namespace std;
int a[1100][1100];
int main(){
	int T,n,m,p,x,y,z,q;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&p);
		memset(a,0,sizeof(a));
		int flag1 = 0,flag2 = 0;
		for(int i=1;i<=p;i++){
			scanf("%d%d%d",&x,&y,&z);
		
			a[(m*x+y)/m][(m*x+y)%m]=z; 
			if(m*x+y<0||m*x+y>=m*n)flag1 = 1;
			if(x<0||y<0)flag2 = 1;
		}
		if(flag1==0){
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					if(j!=(m-1))
					printf("%d ",a[i][j]);
					else printf("%d\n",a[i][j]);
				}
			}
		if(flag2==0){
			printf("Accepted\n");
		}
		else 
			printf("Undefined Behaviour\n");
		}
		else 
			printf("Runtime error\n");
		
		
	}
	return 0;
}
