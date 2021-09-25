#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int a[600][100];
	a[0][1]=0;
	a[0][2]=1;
	a[0][3]=0;
	a[0][4]=0;
	a[0][5]=0;
	a[0][6]=0;
	a[1][1]=1;
	a[1][2]=1;
	a[1][3]=0;
	a[1][4]=1;
	a[1][5]=0;
	a[1][6]=0;
	for(int i=2;i<=60;i++){
		a[i][1]=a[i-1][2]+a[i-1][3];
		a[i][2]=a[i-1][1]*2+1;
		a[i][3]=a[i][2]-i/2-1;
		a[i][4]=a[i][1];
		a[i][5]=a[i][1]-(i+1)/2;
		a[i][6]=a[i][2]-i/2-1;
		a[i][0]=a[i][1]+a[i][2]+a[i][3]+a[i][4]+a[i][5]+a[i][6];
	}
	int n;
	cin>>n;
	printf("A->B:%lld\nA->C:%lld\nB->A:%lld\nB->C:%lld\nC->A:%lld\nC->B:%lld\nSUM:%lld\n",a[n-1][1],a[n-1][2],a[n-1][3],a[n-1][4],a[n-1][5],a[n-1][6],a[n-1][0]);
	return 0;
}
