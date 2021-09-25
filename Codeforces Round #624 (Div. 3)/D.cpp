#include<bits/stdc++.h>
using namespace std;
#define int long long
#define de(x) cerr<<#x<<"="<<x<<endl
void solve(){
	
}
signed main(){
	int t,a,b,c;
	cin>>t;
	int d,e,f,l;
	while(t--){
		int ans=40000;
		cin>>a>>b>>c;
		for(int i=1;i<=10000;i++){
			for(int k=i,j=1;k*j<=10000;j++){
				if(ans>abs(i-a)+abs(k*j-b)+min(c%(k*j),k*j-c%(k*j))){
					l=min(c%(k*j),k*j-c%(k*j));
					ans=abs(i-a)+abs(k*j-b)+l;
					d=i;e=k*j;
					if((c+l)%e==0)f=c+l;else f = c-l;
				}
			}
		}
		cout<<ans<<endl;
		cout<<d<<" "<<e<<" "<<f<<endl;
		
	}	
} 
