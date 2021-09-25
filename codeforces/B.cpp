#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;



signed main(){
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		string s;
		cin>>s;
		
		int l = s.length();
		s += '9';
		int cnt = 0;
		while(s[cnt]=='0')cnt++;
		
		int ans = 0;
		if(s[cnt]=='1'){
			ans+=a;
			while(s[cnt]=='1')cnt++;
		}
		int cnt1 = 0;
		int cnt2 = 0;
		
		
		
		int now = 0;
		for(int i = cnt;i<l;i++){
			if(s[i]=='1')continue;
			int cnt3 = 0;
			while(s[i]=='0')i++,cnt3++;
			if(s[i]=='1'){
				ans += min(cnt3*b,a);
			}
			
		}
		cout<<ans<<endl;
		
	}
}

