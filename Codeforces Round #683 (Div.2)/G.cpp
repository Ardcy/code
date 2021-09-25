#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int arr[N+5];
signed main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int ans = 0;
		int cnt1 = 0, cnt2 = 0;
		int cnt3 = 0, cnt4 = 0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='(')cnt1++;
			if(s[i]=='[')cnt2++;
			if(s[i]==')'&&cnt1){
				ans++;
				cnt1--;
			}
			if(s[i]==']'&&cnt2){
				ans++;
				cnt2--;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
