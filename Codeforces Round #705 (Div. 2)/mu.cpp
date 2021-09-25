#include<bits/stdc++.h>
using namespace std;

const int  N = 1e7+5;
int mu[N],p[N],tot,v[N];

void pre() {
  mu[1] = 1;
  for (int i = 2; i <= 1e7; ++i) {
    if (!v[i]) mu[i] = -1, p[++tot] = i;
    for (int j = 1; j <= tot && i <= 1e7 / p[j]; ++j) {
      v[i * p[j]] = 1;
      if (i % p[j] == 0) {
        mu[i * p[j]] = 0;
        break;
      }
      mu[i * p[j]] = -mu[i];
    }
  }
}
signed main(){
  pre();
  for(int i=1;i<=10;i++){
    cout << mu[i] << endl;
  }
}