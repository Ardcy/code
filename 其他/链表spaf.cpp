#include<bits/stdc++.h>
using namespace std;
#define RANGE 101
#define MAX 0x3f3f3f3f
int cost[RANGE][RANGE];
int d[RANGE];
bool used[RANGE];
int n,m;
void spfa( int s )
{
    int i,now;
    for( i=1;i<=n;++i )
    {
        d[i]=MAX;
        used[i]=false;
    }
    d[s]=0;
    queue <int> q;
    q.push(s);
    used[s] = true;
    while(!q.empty())
    {
        now = q.front();
        q.pop();
        used[now] = false;
        for(i = 1; i <= n; i++)
        {
            if(d[i] > d[now] + cost[now][i])
            {
                d[i] = d[now] + cost[now][i];
                if(used[i] == 0)
                {
                    q.push(i);
                    used[i] = true;
                }
            }
        }
    }
}
int main()
{
    int i,j,A,B,C;
    while( scanf("%d%d",&n,&m) )
    {
        if( !n && !m )  break;
        // ≥ı ºªØ
        for( i=1;i<=n;++i )
            for( j=1;j<=i;++j )
                if( i==j )  cost[i][j]=0;
                else    cost[i][j]=cost[j][i]=MAX;
        for( i=0;i<m;++i )
        {
            scanf("%d%d%d",&A,&B,&C);
            cost[A][B]=cost[B][A]=C;
        }
        spfa(1);
        printf("%d\n",d[n]);
    }
    return 0;
}



