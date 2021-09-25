
#include<iostream>

#include<string>

#include<cstdio>

typedef long long ll;

using namespace std;

const int maxn=100000+5;

int n;

ll ai[maxn],bi[maxn];

ll exgcd(ll a,ll b,ll &x,ll &y)

{

    if(b==0){ x=1, y=0; return a;}

    ll gcd=exgcd(b,a%b,x,y);

    ll tp=x;

    x=y, y=tp-a/b*y;

    return gcd;

}

ll mult(ll a,ll b,ll mod){

    long long res=0;

    while(b>0){

        if(b&1) res=(res+a)%mod;

        a=(a+a)%mod;

        b>>=1;

    }

    return res;

}

ll excrt(){

    ll x,y;

    ll ans=bi[1],M=ai[1];

    for(int i=2;i<=n;++i){

        ll a=M,b=ai[i],c=(bi[i]-ans%ai[i]+ai[i])%ai[i];

        ll gcd=exgcd(a,b,x,y);

        x=mult(x,c/gcd,b/gcd);

        ans+=x*M;

        M*=b/gcd;

        ans=(ans%M+M)%M;

    }

    return (ans%M+M)%M;

}

int main(){

    cin>>n;

    for(int i=1;i<=n;++i)

        cin>>ai[i]>>bi[i];

    cout<<excrt();

}

