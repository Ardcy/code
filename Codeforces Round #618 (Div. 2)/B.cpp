#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+50;
int a[N];
int inf = 1e9;
int b[40];
int c[N];
signed  main(){
	int T,n,sum,maxn,p;
	T = 1;

	while(T--){
		cin>>n;
		sum = 0;
		
		maxn = inf;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		cout<<a[n];
		sum = a[n];
		for(int i=1;i<=40;i++){
			if(sum%2)b[i]=1;
			sum/=2;
		}
		for(int i=1;i<=40;i++){
			if(b[i])
			for(int j=1;j<=n-1;j++){
				if(!c[j]&&(a[j]&(1<<(i-1)))){
					cout<<" "<<a[j];
					c[j]=1;
					p = a[j];
					for(int y = 1;y<=40;y++){
						if(p%2)b[y]=0;
						p/=2;
					}
				}
			}
		}
		for(int i = 1;i<n;i++){
			if(!c[i])cout<<" "<<a[i];
		}


	}
}
