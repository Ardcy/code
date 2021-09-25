#include<bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int maxn = 1e5+5;
struct node {
    int p,a,id;
} car[maxn],robot[maxn],S[maxn];
int n;
int via[maxn];
 
int rule( node a, node b )
{
    if ( a.p==b.p ) return a.a>b.a;
    return a.p>b.p;
}
 
signed main()
{
    //freopen("t.in","r",stdin);
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;cin>>T;
    while ( T-- ) {
        cin>>n;
        for ( int i=0; i<n; i++ ) {
            scanf("%lld %lld",&car[i].p,&car[i].a);
            //cin>>car[i].p>>car[i].a;
            car[i].id = i+1;
            via[i+1] = 0;
        }
        sort(car,car+n,rule);
        robot[0]=car[0];
        int cnt = 1, lasta=car[0].a;
        for ( int i=1; i<n; i++ ) {
            if ( car[i].a==car[i-1].a && car[i].p==car[i-1].p ) {
                via[ car[i].id ] = 1;
                via[ car[i-1].id ] = 1;
            }
            if ( car[i].a>lasta ) {
                robot[cnt++] = car[i];
                lasta = car[i].a;
            }
        }
        int pos = 0;
        for ( int i=0; i<cnt; i++ ) {
            while ( pos>1 ) {
                node t1 = S[pos-1];
                node d = S[pos-2];
                node t2 = robot[i];
                if ( (t2.p-d.p)*(d.a-t1.a)>(t1.p-d.p)*(d.a-t2.a) ) {
                    break;
                }
                else {
                    pos --;
                }
            }
            S[pos++] = robot[i];
        }
        int ans = 0;
        for ( int i=0; i<pos; i++ ) {
            node t = S[i];
            if ( via[t.id]==0 ) ans++;
        }
        cout << ans << endl;
    }
 
    return 0;
}