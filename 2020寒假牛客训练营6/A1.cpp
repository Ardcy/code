#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define random(a,b)  (rand()%(b-a+1)+a)
typedef long long ll;
struct node
{
    int sum;//��������������Ԫ�غ�
    int index;//��ʾ����a���±�
};
bool operator < (node aa,node bb)
{
    return aa.sum>bb.sum;//����������С�ں�
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
         nn.sum=a[1]+b[i];//�����Ƚ����е�bԪ����a�ĵ�һ��Ԫ����ӣ��õ��ĵ�һ���϶������Ž⣬�����ļ����ظ��ò���
         heep.push(nn);//��������Ԥ����
     }
     while(n--)//���ɶ��еĴ�ȡ����ʵ�����������ȶ��е��ص�
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

