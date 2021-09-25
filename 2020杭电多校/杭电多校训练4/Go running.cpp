#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int t;
	scanf("%lld",&t);
	while(t--){
		set<int>st;
		int ans = 0;
		int n;
		cin >> n;
		for(int i=1;i<=n;i++){
			int a,b;
			cin >> a >> b;
			if(st.count(b+a)&&st.count(b-a)){
				continue;
			}
			if(st.count(b+a)){
				st.insert(b+a);
				continue;
			}
			if(st.count(b-a)){
				st.insert(b-a);
				continue;
			}
			st.insert(b+a);st.insert(b-a);
			ans++;
		}
		//cout << st.size() << endl;
		cout << st.size() - ans << endl;

	}
}