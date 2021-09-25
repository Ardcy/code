#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p = 1e9+7;

double ans[2020][2020];
int main() {
    int n;
    n = 10;
    double ps[11]={0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1};
    
    ans[0][0] = 1;
    for(int i=1;i<=n;i++){
        ans[i][0] = ans[i-1][0]*(1-ps[i]);
        for(int j=1;j<=n;j++){
            ans[i][j] = (ans[i-1][j]*(1-ps[i]) + ans[i-1][j-1]*ps[i]);
        }
    }
    
    cout<<ans[n][5]<<endl;
    return 0;
}
