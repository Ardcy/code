#include<bits/stdc++.h>
using namespace std;

#define int long long


typedef std::subtract_with_carry_engine<std::uint_fast64_t, 48, 5, 12> ranlux48_base;
ranlux48_base rb;

int p[1000];
signed main() {
	srand(rand());
	cout<<1<<endl;
	int n;
	n = rand()%100;
	n+=1;
	cout<<n<<endl;
	for(int i=1;i<=n;i++){
		int c = rand()%100+1, d = rand()%100;
		d = c+d;
		for(int j=c;j<d;j++){
			p[j]+=1;
		}
		cout<<c<<" "<<d<<endl;
	}
	int u = 0;
	for(int i=1;i<=999;i++){
		u=max(u,p[i]);
	}
	cout<<u<<endl; 
	return 0;
}
