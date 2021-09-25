#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#define ll long long
using namespace std;
#define N 205000
long long int A[N];
int main()
{
	int T;
	cin>>T;
	while(T--){
		long long int m,n;
		int hh=0;
		cin>>n>>m;
		getchar();
		int u=0;
		for(int i=1;i<=n;i++){
			char c;
			c=getchar();
			A[i]=c-'0';
			A[n+i]=A[i];
			if(!A[i])u++;
			else u--;
		}
	int y=0,k=0;
	for(int i=1;i<=n;i++){
			if(!A[i])y++;
			else y--;
			
			if(u!=0&&(m-y)%u==0&&(m-y)/u>0)k++;
			if(u==0&&m==y)hh++;
	}
				if(!hh)cout<<k+(!m)<<endl;
				else cout<<-1<<endl;
	}
    
    return 0;
}
