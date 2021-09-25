#include<bits/stdc++.h>
using namespace std;
#define N 205000
#define int long long
const int mod = 1e9+7;
char a[N];
int dp[N];
signed main(){
   int n;
   cin>>n;
   cin>>a;
   int pre = -1;
     for(int i=0;i<N;i++){
   		if(a[i]=='1'){
   			pre = i;
   			break;
		}	
   }

   if(pre==-1){
   		cout<<0;
	    return 0;
   }
   int cnt = 0;
   int ans = 0;
   
   for(int i=pre+1;i<n;i++){
   		if(a[i]=='1'){
   			cnt++;
   			dp[i] = cnt*(i-pre) + dp[pre];
			dp[i] %=mod;
   			ans+=dp[i];
   			ans%=mod;
			pre=i;
				
		}	
   }
   cout<<ans<<endl;
}
