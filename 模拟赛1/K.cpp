#include<bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
double t[200006],s[200006],a[200006];
struct node{
    double time,k,b,t;
    bool operator < (const node &n)const{
        return time < n.time;
    }
};
double solve(int n){
    vector<node>v;
    for(int i=1;i<=n;i++){
      double r = min(pi - 1e-8,t[i]/s[i]);
      v.push_back({a[i] - r,s[i],-a[i]*s[i],t[i]});
        v.push_back({a[i],-2*s[i],2*a[i]*s[i],0});
        v.push_back({a[i]+r,s[i],-a[i]*s[i],-t[i]});
        a[i] += 2*pi;
        v.push_back({a[i] - r, s[i], -a[i]*s[i],t[i]});
        v.push_back({a[i],-2*s[i],2*a[i]*s[i],0});
        v.push_back({a[i]+r,s[i],-a[i]*s[i],-t[i]});
        a[i] -= 2*pi;
    }
    sort(v.begin(),v.end());
    double T = 0, K = 0, B = 0, ans = 0;
    for(auto p:v){
        K += p.k;
        B += p.b;
        T += p.t;
        ans = max(ans,T + K*p.time + B);
    }
    return ans;
}
signed main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> t[i] >> s[i] >> a[i];
    }
    cout << fixed << setprecision(10) << solve(n)<<endl;
}