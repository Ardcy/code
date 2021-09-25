#include<bits/stdc++.h>
#define de(x) cerr<<#x<<"="<<x<<endl
using namespace std;
int sum[100000];
int a[100000];
int main(){
	int n,m;
	cin>>n>>m;sum[n+1]=1000000007;
	for(int i=1;i<=n;i++){
		a[i]=(i-1)/2;
		sum[i]=sum[i-1]+a[i];
	}
	if(sum[n]<m){
		puts("-1");
		return 0;
	}
	
	else{
		int index = 1;
		for(int i=1;i<=n;i++){
			if(sum[i]>m){
				index = i;
				break;
			}
		}
		m-=sum[index-1];
		for(int i=1;i<index;i++){
			cout<<i<<" ";
		}
		if(m!=0){
			cout<<(index-1)+2*m<<" ";
			index++;
		}
		for(int i=index;i<=n;i++){
			cout<<50000000+i*100000<<" ";
		}
		
	}
	
}
