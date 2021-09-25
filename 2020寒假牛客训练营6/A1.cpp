#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define random(a,b)  (rand()%(b-a+1)+a)
typedef long long ll;
struct node
{
    int sum;//求两个序列任意元素和
    int index;//表示序列a的下标
};
bool operator < (node aa,node bb)
{
    return aa.sum>bb.sum;//降级，重载小于号
}
ll a[100005];
ll b[100005];
priority_queue<node>heep;
int main ( )
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
     int n;
     int k,w;
     cin>>n>>k;
     int u = n-k;
     n = k;
     for(int i=1;i<=u;i++)
      cin>>w;
     for(int i=1;i<=n;i++)
     cin>>a[i];
     for(int i=1;i<=u;i++)
      cin>>w;
     rep(i,1,n)
     if(i>=k) cin>>b[i];
     sort(a+1,a+1+n);
     sort(b+1,b+1+n);
     node nn;
     rep(i,1,n)
     {
         nn.index=1;
         nn.sum=a[1]+b[i];//这里先将所有的b元素与a的第一个元素相加，得到的第一个肯定是最优解，其他的继续重复该操作
         heep.push(nn);//这里先是预处理
     }
     while(n--)//看成队列的存取，其实就是运用优先队列的特点
     {
         nn=heep.top();
         heep.pop();
         cout<<nn.sum<<" ";
         nn.index++;
         nn.sum+=a[nn.index]-a[nn.index-1];
         heep.push(nn);
     }
     cout<<endl;
   return 0;
}

