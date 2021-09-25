#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
int arr[N];
int drr[N];

double check(int x,int y){
	double res = 0.0;
	int t1 = ((100+arr[x]-1) / arr[x] -1 ) * drr[x];
	int t2 = ((100+arr[y]-1) / arr[y] - 1) * drr[y];
	if(t1==t2){
		return 0.5;
	}
	if(t1 > t2){
		return 0.0;
	}
	if(t2 > t1){
		return 1.0;
	}

}
signed main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&arr[i],&drr[i]);
		}
		double ansp = 0.0;
		for(int i=1;i<=n;i++){
			double ansp1 = 0.0;
			for(int j=1;j<=n;j++){
				ansp1 += check(i,j) / n;
			}
			ansp = max(ansp1,ansp);
		}
		printf("%.10f\n",ansp);
	}
}