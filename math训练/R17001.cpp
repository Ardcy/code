#include<bits/stdc++.h>
using namespace std;
const int N = 5000000;
int num[N];
int isp[N];
int n,m,t,ans,cnt;
void init(){
	memset(num,0,sizeof(num));
	isp[1]=1;
	for(int i=2;i<=N;i++){
		if(!isp[i]){
			for(int j=i;j<=N;j+=i){
				int temp=j;
				while(temp%i==0){
					num[j]++;
					temp/=i;
				}
				isp[j]=1;
			}
		}
	}
	for(int i=2;i<=N;i++)num[i]=num[i-1]+num[i];
	
}
signed main(){
	init();
	int t;
	cin>>t;
	while(t--){
		scanf("%d%d",&n,&m);
		printf("%d\n",num[n]-num[m]);
	}
	return 0;
}
