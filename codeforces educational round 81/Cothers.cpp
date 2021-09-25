#include<bits/stdc++.h>
using namespace std;
int T;
char s[100005],t[100005];
int nxt[100005][26];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s+1);
        scanf("%s",t+1);
        int n=strlen(s+1),m=strlen(t+1);
        for(int j=0;j<26;++j)nxt[n][j]=0;
        for(int i=n-1;i>=0;--i)
        {
            for(int j=0;j<26;++j)nxt[i][j]=nxt[i+1][j];
            nxt[i][s[i+1]-'a']=i+1;
        }
        int now=0,ans=1;
        for(int i=1;i<=m;++i)
        {
            now=nxt[now][t[i]-'a'];
            if(!now)
            {
                ans++;
                now=nxt[now][t[i]-'a'];
                if(!now){ans=-1;break;}
            }
        }
        printf("%d\n",ans);
    }
}
