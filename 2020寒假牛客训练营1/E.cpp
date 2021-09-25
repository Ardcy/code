#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    
    int n;
    cin>>n;
    
    int cnt = sqrt(n);
    int hj = 0;
    int ans = 0;
    for(int i=1;i*i<=n;i++){
    	ans+=sqrt(n/i);
    }
    
    cout<<ans<<endl;
    
}
