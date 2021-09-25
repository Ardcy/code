#include<bits/stdc++.h>
using namespace std;
const int maxn = 2010;
const int inf = INT_MAX;
int num[maxn];
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
signed main(){
	int n;
	while(cin>>n){
		int cnt_1=0;
		int ans = inf;
		for(int i=0;i<n;i++){
			cin>>num[i];
			if(num[i]==1)cnt_1++;
		}
		if(cnt_1){
			cout<<n-cnt_1<<endl;
		}
		else{
			for(int i=0;i<n;i++){
				int x=num[i];
				for(int j=i+1;j<n;j++){
					x=gcd(x,num[j]);
					if(x==1){
						ans=min(ans,j-i);
					}
				}
//				cout<<x<<" "<<ans<<endl;
			}
			if(ans==inf)cout<<-1<<endl;
			else cout<<ans+n-1<<endl;
		}
	}
	return 0;
}
