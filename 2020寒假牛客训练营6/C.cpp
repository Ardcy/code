#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+50;
int a[N];
const int mod = 998244353;
int sum = 0;
int exgcd(int a, int b, int &x, int &y) {         //x��y��ʼΪ����ֵ������Ϊһ���ؽ�
    if(b == 0) {        //��Ӧ���������a=gcd(a,b),b=0,��ʱx=1��yΪ������
        x = 1;
        y = 0;
        return a;
    }
    int r = exgcd(b, a % b, x, y);      //�ȵݹ鵽����������ٷ��Ƴ���ʼ���
    int t = x; x = y; y = t - a / b * y;
    return r;     //gcd(a,b)
}
int R(int a,int b,int n)
{
    int X,Y,d;
    long long res;
    long long min_res;
    d=__gcd(a,n);
    exgcd(a,n,X,Y);
    if(b%d == 0)
    {
        X = X * (b / d) % n;//�õ�ͬ�ڷ���һ��
        for(int i = 0 ; i < d; i++)
        {
            res = (X + (i * (b/d))) % n;
            //printf("%lld\n",res);             //������Խ�
        }
        min_res=(X%(n/d)+(n/d))%(n/d);    
        return min_res; 
    }
}
signed main() {
	int n,k,f;
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		a[i]%=mod;
	}
	int mid = 1;	
	int cnt = 0;
	for(int i = 1;i<=n;i++){
		if(a[i]==0)
		{
			mid = 1;
			cnt = 0;
			if(i>n)break;
			continue;
		}	
		if(cnt==k){
			mid = R(a[i-k],mid,mod)*a[i];
			mid%=mod;
		}
		if(cnt<k){
			mid *= 	a[i];
			mid%=mod;
			cnt++;
		}
		if(cnt==k){
			sum = max(sum,mid);
		}
		//cout<<"i="<<i<<" "<<"cnt="<<cnt<<" "<<"mid="<<mid<<endl;
	}
	cout<<sum<<endl;
	return 0;
}
