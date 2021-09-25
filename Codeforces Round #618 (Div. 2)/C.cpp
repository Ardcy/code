#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long 
const int maxn = 200005,mod=1000000007;
int a[maxn][35],t[maxn];
 
signed main(){
 
    int n;
    cin>>n;
    // for(int i=1;i<=n;i++){
    //     cin>>a[i];
    // }
    // sort(a+1,a+1+n);
    int ans=0,manxj=1;
    for(int i=1;i<=n;i++){
        int temp;
        cin>>t[i];
        temp=t[i];
        for(int j=1;j<=31;j++){
            if(temp&1==1){
                a[i][j]=1;
                //if(manxj<j) manxj=j,ans=temp;
            }
            temp>>=1;
        }
    }
    for(int j=31;j>=0;j--){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i][j]==1) cnt++,manxj=i;
        }
        if(cnt==1){
            break;
        }
    }
    cout<<t[manxj];
    for(int i=1;i<=n;i++)
        if(i!=manxj) cout<<" "<<t[i];
    cout<<endl;
    return 0;
}
