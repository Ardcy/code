#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 9e15;
signed main(){
	srand(time(0));
	//freopen("in.txt","w",stdout);
	int t = 1;
	cout << t << endl;
	for(int i=1;i<=t;i++){
		int p1 = rand();
		int p2 = rand();
		int p3 = rand();
		int p4 = rand();
		int d =  ((p1<<48)|(p2<<32)|(p3<<16)|(p4<<16));

		p1 = rand();
		p2 = rand();
		p3 = rand();
		p4 = rand();
		int p =  ((p1<<48)|(p2<<32)|(p3<<16)|(p4<<16));
		p%=mod;
		d%=mod;
		if(p>d)swap(p,d);
		//cout << p%mod << " " << d%mod <<" " << rand()%11 << endl;
		cout <<p << endl;
	}

}