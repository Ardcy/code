#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int Mod = 1e9 + 7;
int bit[20];
ll byte[20];
struct node
{
    ll cnt, sum, ssum;
    node(){cnt = -1; sum = 0; ssum = 0;}  //这里用于新node一个struct的初始化
    node (ll cc, ll ss, ll ssss) : cnt(cc), sum(ss), ssum(ssss){}
 
}dp[22][10][10];
node dfs(int len, int sremd, int nremd, int limit)
{
    if(len < 1) return  sremd && nremd ? node(1, 0, 0) : node(0, 0, 0); //这里如果位数小于个位了，如果两个条件达到的话，说明它符合了，数量+1
    if(!limit && dp[len][sremd][nremd].cnt != -1) return dp[len][sremd][nremd]; //通过结构体初始化判断是否访问过，秒啊
    int last = limit ? bit[len] : 9;
    node ans; ans.cnt  = 0;
    for(ll i = 0; i <= last; i++)
    {
        if(i == 7) continue;
        node temp = dfs(len-1, (sremd + i)%7, (nremd*10 + i)%7, i == last && limit); //这里也没见过，直接找后面位数的状态，真正的递归思想，因为这一位的状态取决于后面的状态的
        ans.cnt = (ans.cnt + temp.cnt) % Mod;
        ll r = ((i*byte[len])%Mod*temp.cnt%Mod)%Mod;  //不断Mod。。
        ll r1 = (i*byte[len])%Mod;
        ans.sum = (ans.sum + (r + temp.sum)%Mod)%Mod;
        ans.ssum = (ans.ssum + (temp.ssum + (((r1 * r1)%Mod)*temp.cnt)%Mod + ((2 * r1)%Mod*temp.sum)%Mod)%Mod)%Mod;
    }
    if(!limit) dp[len][sremd][nremd] = ans;
    return ans;
}
ll cal(ll n)
{
    int k = 0;
    while(n)
    {
        bit[++k] = n % 10;
        n /= 10;
    }
    return dfs(k, 0, 0, 1).ssum;
}
void init()
{
    byte[1] = 1;
    for(int i = 2; i < 20; i++)
        byte[i] = (byte[i-1]*10) % Mod;
}
int main()
{
    int t;
    init();
    scanf("%d", &t);
    while(t--)
    {
        ll l, r;
        scanf("%I64d%I64d", &l, &r);
     //   cout << cal(r) << endl << cal(l-1) << endl;
        printf("%I64d\n", ((cal(r)-cal(l-1))%Mod+Mod)%Mod);  //长知识，因为这里cal都是区域之后的值，可能导致这里是是负数，所以要先+Mod然后再对整体Mod
    }
    return 0;
}