#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int a,b,c;
	cin>>a>>b>>c;
	int ans1=min(a,min(b,c));
	a-=ans1;
	b-=ans1;
	c-=ans1;
	ans1+=a/3+b/3+c/3;
	a=a%3;
	b=b%3;
	c=c%3;
	if(a>b)swap(a,b);if(b>c)swap(b,c);if(a>b)swap(a,b);
	if(b==2&&c==2)
	cout<<ans1+1<<endl;else cout<<ans1<<endl;
	return 0;
}
