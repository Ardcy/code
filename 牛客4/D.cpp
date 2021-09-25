#include<bits/stdc++.h>
using namespace std;
#define int long long

int f(int x){
	int ans = 0;
	while(x){
		ans += (x%10)*(x%10);
		x/=10;
	}
	return ans;
}

signed main(){
	int n;
	cin >> n;
	int flag = 1;
	set<int>P;
	P.insert(n);
	while(f(n)!=1){
		n = f(n);
		if(P.count(n)){
			flag = 0;break;
		}
		P.insert(n);
	}
	if(flag){
		cout <<"HAPPY" << endl;
	}else{
		cout <<"UNHAPPY" << endl;
	}

}