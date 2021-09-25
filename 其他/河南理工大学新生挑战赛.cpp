#include<bits/stdc++.h>
using namespace std;
int main(){
	int A[1005]={0},B[1005]={0};
	int M,N,n;
	cin>>M>>N;
	int T;
	scanf("%d",&T);
	n=T;
	while(T--){
		int a,b;
		scanf("%d%d",&a,&b);
		A[a]=1-A[a];
		B[b]=1-B[b];
	}
	int x=0,y=0;
	for(int i=1;i<=M;i++)if(A[i])x++;
	for(int i=1;i<=N;i++)if(B[i]){
		y++;
		printf("11%d\n",i);
	}
	printf("x=%d,,,y=%d",x,y);
	printf("%d\n",y*M+x*N-x*y);
	return 0;

}
