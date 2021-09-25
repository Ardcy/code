#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000];
int b[2000];
int c[11];
int d[11];
int c1[11];
int d1[11];
signed main(){
	int n;
	scanf("%lld",&n);
	getchar();
	for(int i=1;i<=n;i++){
		a[i]=getchar()-'0';
		c[a[i]]++;
	}
	getchar();
	for(int i=1;i<=n;i++){
		b[i]=getchar()-'0';
		d[b[i]]++;
	}
	for(int i=0;i<=9;i++){
		c1[i]=c[i],d1[i]=d[i];
	}
	int ans1=0;
	for(int i=0;i<=9;i++){
		while(c1[i]){
			int ff=0;
			for(int j=i;j<10;j++){
				if(d1[j]){
					d1[j]--;
					c1[i]--;
					ans1++;
					ff=1;
					break;
				}
			}
			if(ff==0)break;
		}
	}
	cout<<n-ans1<<endl;
	
	int ans2=0;
	for(int i=0;i<=9;i++){
		
		while(c[i]){
			int ff=0;
			for(int j=i+1;j<10;j++){
				if(d[j]){
					d[j]--;
					c[i]--;
					ans2++;
					ff=1;
					break;
				}
			}
			if(ff==0)break;
		}
	}
	cout<<ans2<<endl;
	return 0;
}
