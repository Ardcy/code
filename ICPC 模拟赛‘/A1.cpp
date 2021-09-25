#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int N = 1e6+5;
int ans1[N];
signed main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	d = min(d,a+b+c);
	a = min(a,d),b=min(a,d),c = min(c,d);
	ans1[0] = 1;
	for(int i=1;i<=d;i++){
		int a1 = min(a,i);
		int b1 = min(b,i);
	//	cout<< a1 << " "<< b1<<endl;
		if(a1+b1<i){
			ans1[i] = ans1[i-1];
		}
		else{
			ans1[i] = ans1[i-1]+ a1+b1-i+1;
		}
	}
	int ans = 0;
	for(int i=0;i<=a;i++){
		ans+=ans1[d-i];
	}
	cout<<ans<<endl;
	
}
