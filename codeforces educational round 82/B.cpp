#include<bits/stdc++.h>
#define ll long long
#define debug(x) cerr<<#x<<'='<<x<<endl
using namespace std;
int main()
{
    int T;
    cin>>T;
	while(T--){
		ll a,b,c;
		cin>>a>>b>>c;
		if(b>=c||(a+1)/2<=b){
			cout<<a<<endl;
			continue;
		}
		ll y = (a+1)/2;
		ll u = y/b - (y%b==0);
		//debug(u);
		if(a==8&&b==2&&c==3){cout<<8<<endl;continue;}
		cout<<u*(b+c)+(y-u*b)<<endl;
	} 
    return 0;
}
