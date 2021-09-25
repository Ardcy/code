#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
} 
signed main()
{
    int n, m, x, y, a, b;
	cin>>n>>m>>x>>y>>a>>b;
    int g = gcd(a,b);
    a /= g, b /= g;
    int t = min(n/a,m/b);
    a = a*t, b = b*t;
    int down = x-(a+1)/2;
    if(down < 0)
        down = 0;
    else if(down + a > n) down -= down+a-n;
    int up = y-(b+1)/2;
    if(up < 0) up = 0;
    else if(up + b > m) up -= up+b-m;
    printf("%lld %lld %lld %lld\n",down, up, down+a, up+b);
    return 0;
}

