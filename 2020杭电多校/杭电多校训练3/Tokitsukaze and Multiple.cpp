#include<bits/stdc++.h>
using namespace std;
#define int long long 
inline int read(){
	int p;
	scanf("%lld",&p);
	return p;
}

signed main(){
	int t;
	t = read();
	while(t--){
		int n,p;
		int cnt = 0;
		n = read();p = read();
		set<int>st;
		int pre = 0;
		for(int i=1;i<=n;i++){
			int k;
			k = read();
			pre += k;
			if(pre % p ==0){
				st.clear();
				cnt++ ;
				pre = 0;
				continue;
			}else{

				if(st.count(pre%p)){
					st.clear();
					cnt++;
					pre = 0;
					continue;
				}

				st.insert(pre%p);
			}
		}
		cout << cnt << endl;
	}
}