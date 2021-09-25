#include<bits/stdc++.h>
using namespace std;
signed main() {
	int t,N,M;
	cin>>t>>N>>M;

	for(int i=1; i<=t; i++) {
		stack<int>P;
		int cnt = 1;
		int f = 1;
		for(int j=1; j<=N; j++) {
			int u;
			cin>>u;
			if(u>=cnt)
				while(cnt<=u) {
					P.push(cnt++);
					if(P.size()>M) {
						cout<<cnt<<endl;
						cout<<"1"<<endl;
						f=0;
						break;
					}
				}
			else if(u<cnt) {
				
				int f1 = P.top();
				if(f1==u)P.pop();
				else {
					cout<<2<<endl;
					f=0;
				//	break;
				}
			}
			//if(f==0)break;

		}
		if(f)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;

	}
}
