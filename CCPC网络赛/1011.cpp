#include<bits/stdc++.h>
using namespace std;

int a[60][60]={0};
int b[4][4]={0};
signed main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		cin>>n;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				scanf("%d",&a[i][j]);
			}
		}
		int sum = 0;
		for(int i=1; i<=3; i++) {
			for(int j=1; j<=3; j++) {
				scanf("%d",&b[i][j]);
				sum+=b[i][j];
			}
		}
		if(b[1][1]==sum) {
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=n; j++) {
					printf("%d",a[i][j]);
					if(j!=n)printf(" ");
				}
				printf("\n");
			}
		}
		else{
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=n; j++) {
					printf("0");
					if(j!=n)printf(" ");
				}
				printf("\n");
			}
			
		}

	}
	return 0;
}


