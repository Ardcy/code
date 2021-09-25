#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<'='<<x<<endl
using namespace std;
#define int long long
int a[105000];
int b[205000];
int m;
signed  main(){
	int T;
	cin>>T;
	while(T--){
		m = 0;
		int n;
		cin>>n;
		int cnt = 0, y;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			
			if(a[i]==-1){
				if(a[i-1]!=-1&&i!=1)b[++cnt]=a[i-1];
				if(a[i+1]!=-1&&i!=n)b[++cnt]=a[i+1];
			}
			if(i!=1&&a[i]!=-1&&a[i-1]!=-1)m=max(m,abs(a[i]-a[i-1]));
		}		
		sort(b+1,b+cnt+1);
		//debug(b[1]);
		y = (b[1]+b[cnt])/2;
		m=max(m,max(y-b[1],b[cnt]-y));
		cout<<m<<" "<<y<<endl;
	}
}
