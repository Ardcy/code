#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int a,b;
	while(~scanf("%lld%lld",&a,&b)){
		if(a<b)swap(a,b);
		int win = 0;
		while(b){
			if(a%b==0||a/b>=2)break;
			a = a - b;
			swap(a,b);
			win^=1;
		}
		if(win==0)cout<<"Stan wins"<<endl;
		else cout<<"Ollie wins"<<endl;
	}
	return 0;
}
