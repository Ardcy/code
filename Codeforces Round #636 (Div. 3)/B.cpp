#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair

signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if((n/2)%2==1){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
			for(int i=1;i<=n/2;i++){
				cout<<2*i<<" ";
			}
			for(int i=1;i<=n/2;i++){
				if(i<=n/4){
					cout<<2*i-1<<" ";
				}else {
					cout<<2*i+1<<" ";
				}
			
			}
			cout<<endl;
			
		}
	}
	return 0;
}


