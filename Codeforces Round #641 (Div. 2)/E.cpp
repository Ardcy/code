#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3000005;
const int inf = 0x3f3f3f3f;
 
int n,k,a[3000005];
int main() {
    //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T=1; 
    while(T--){
        cin>>n>>k;
        int x = 0,y = 0;
        for(int i = 1;i<=n;i++) {
            cin>>a[i];
            vector<int>v;
            if(a[i] == k) x = 1;
            if(i>=2 && a[i-1]>=k && a[i]>=k) y = 1;
            if(i>=3) {
                v.push_back(a[i]);v.push_back(a[i-1]);v.push_back(a[i-2]);
                sort(v.begin(),v.end());
                if(v[1] == k) y = 1;
            }
        }
        if(n==1&&a[1]==k) cout<<"yes"<<'\n';
        else if(x&&y) cout<<"yes"<<'\n';
        else cout<<"no"<<'\n';
   }
}
