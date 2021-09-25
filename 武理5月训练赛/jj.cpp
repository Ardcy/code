#include<iostream>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<cstdlib>
#include<set>
#include<map>
#include<ctime>
#include<stack>
#include<queue>
#include<vector>
#include<set>
using namespace std;
#define int long long
const int  NUM=100;//���������Miller_Rabin�㷨Ϊ�������㣬������Ϊ2^(-NUM);
#define ll long long
ll t,f[100];
ll mul_mod(ll a,ll b,ll n)//��a*b%n������a��b̫����Ҫ�ý�λ�˷�
{
    a=a%n;
    b=b%n;
    ll s=0;
    while(b)
    {
        if(b&1)
            s=(s+a)%n;
        a=(a<<1)%n;
        b=b>>1;
    }
    return s;
}
ll pow_mod(ll a,ll b,ll n)//��a^b%n
{
    a=a%n;
    ll s=1;
    while(b)
    {
        if(b&1)
            s=mul_mod(s,a,n);
        a=mul_mod(a,a,n);
        b=b>>1;
    }
    return s;
}
bool check(ll a,ll n,ll r,ll s)
{
    ll ans=pow_mod(a,r,n);
    ll p=ans;
    for(ll i=1;i<=s;i++)
    {
        ans=mul_mod(ans,ans,n);
        if(ans==1&&p!=1&&p!=n-1)
            return true;
        p=ans;
    }
    if(ans!=1) return true;
    return false;
}
bool Miller_Rabin(ll n)//Miller_Rabin�㷨���ж�n�Ƿ�Ϊ����
{
    if(n<2) return false;
    if(n==2) return true;
    if(!(n&1)) return false;
    ll r=n-1,s=0;
    while(!(r&1)){r=r>>1;s++;}
    for(ll i=0;i<NUM;i++)
    {
        ll a=rand()%(n-1)+1;
        if(check(a,n,r,s))
            return false;
    }
    return true;
}
ll gcd(ll a,ll b)
{
    return b==0?a:gcd(b,a%b);
}
ll Pollard_rho(ll n,ll c)//Pollard_rho�㷨���ҳ�n������
{
    ll i=1,j,k=2,d,p;
    ll x=rand()%n;
    ll y=x;
    while(true)
    {
        i++;
        x=(mul_mod(x,x,n)+c)%n;
        if(y==x) return n;
        if(y>x) p=y-x;
        else p=x-y;
        d=gcd(p,n);
        if(d!=1&&d!=n) return d;
        if(i==k)
        {
            y=x;
            k+=k;
        }
    }
}
void find(ll n)//�ҳ�n����������
{
    if(Miller_Rabin(n))
    {
        f[t++]=n;//������������
        return;
    }
    ll p=n;
    while(p>=n)p=Pollard_rho(p,rand()%(n-1)+1);//����p�ض�Ϊ����������ͨ��������ض�����ô�
    find(p);
    find(n/p);
}
signed main()
{
    srand(time(NULL));//������趨����
    ll n;cin>>n;
    int h = n;
    n=n*n+1;
    
	//if(n==1){cout<<"1"<<endl;return 0;}
    t=0;
    find(n);
    sort(f,f+t);
    map<ll,int>q;
    for(int i=0;i<t;i++)
    {
        q[f[i]]++;
    }
    map<ll,int>::iterator it;
    ll ans=1;
    for(it=q.begin();it!=q.end();it++)
    {
        int s=it->second;
       // cout<<s<<endl;
        ans*=1+s;
    }
    //cout<<ans<<endl;
	ans=(ans)/2;
    cout<<h-ans<<endl;
    return 0;
}
