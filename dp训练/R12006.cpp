#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T; scanf("%d", &T); while(T--)
    {
        int N, a, b, c;
        char str[999];
        char ans[999];
        int cnt = 0;
        scanf("%d%d%d%d%s", &N, &a, &b, &c, str);
        for(int i=0; i<N; ++i)
        {
            ans[i] = '?';
            if(str[i]=='R' && b) --b,ans[i] = 'P',++cnt;
            if(str[i]=='P' && c) --c,ans[i] = 'S',++cnt;
            if(str[i]=='S' && a) --a,ans[i] = 'R',++cnt;
        }
        if(cnt <(N+1)/2)
        {
            puts("NO");
            continue;
        }
        for(int i=0; i<N; ++i)
        {
            if(ans[i] != '?') continue;
            if(a) ans[i] = 'R',--a;
            else if(b) ans[i] = 'P',--b;
            else if(c) ans[i] = 'S',--c;
            
        }
        ans[N] = 0;
        puts("YES");
        puts(ans);
    }    
}
