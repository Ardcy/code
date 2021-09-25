#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int arr[N+5];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n,c0,c1,h;
		cin>>n>>c0>>c1>>h;
		string s;
		cin>>s;
		int ans = 0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='0'){
				ans += min(c0,h+c1);
			}else{
				ans += min(c1,h+c0);
				
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
