#include<bits/stdc++.h>
using namespace std;
#define int long long
int t;
int a[100];
int b[100];
signed main(){
	cin>>t;
	a[1]=1;
	for(int i=2;i<=32;i++){
		a[i]=a[i-1]*2;
	}
	while(t--){
		for(int i=1;i<=70;i++)b[i]=0;
		int d,m;
		cin>>d>>m;
		int d1=d;
		int cnt = 0;
		for(cnt=1;;cnt++){
			if(d1>=a[cnt]){
				b[cnt]=a[cnt];
				d1-=a[cnt];
			}
			else{
				if(d1>0){
					b[cnt]=d1;break;
				}
				else {
					cnt--;
					break;
				}
			}
		}
		int ans=0;
		int c = b[1];
		ans = b[1];
		for(int i=2;i<=cnt;i++){
			c = (ans*b[i]+b[i]);
			c%=m;
			ans+=c;
			ans%=m;
		}
		cout<<ans<<endl;
	}
}
