#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
int po(int a,int b){
	int ans = 1;
	for(int i=1;i<=b;i++)ans*=a;
	return ans;
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int y = 2;
		while(y){
			if(n%(po(2,y)-1)==0){
				cout<<(n/(po(2,y)-1))<<endl;break;
			}
			y++;
		}
	}
	return 0;
}


