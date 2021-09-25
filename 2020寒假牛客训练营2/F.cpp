#include<bits/stdc++.h>
using namespace std;
#define N 205000
#define int long long
int a[N];
int b[N];
struct nod{
    int a1;
    int a2;
}e[N];
bool cmp(nod r,nod t){return r.a1>t.a1;}


signed main(){
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>m,e[i].a1=a[i]+m,e[i].a2=i;
    sort(e+1,e+n+1,cmp);
    for(int i=1;i<=n;i++){
        if(i%2)cout<<e[i].a2<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        if(i%2==0)cout<<e[i].a2<<" ";
    }
}
