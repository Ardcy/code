#include<bits/stdc++.h>
using namespace std;

bool check(string s){
	int cnt = 0;
	int n = s.length();
	for(int i=0;i<n;i++){
		if(s[i] == '('){
			cnt++;
		}else{
			cnt--;
		}
		if(cnt<0)return false;
	}
	if(cnt!=0)return false;
	return true;
}

signed main(){
	int t;
	cin >> t;
	while(t--){
		string str;
		cin >> str;
		map<char,char>mp;
		mp['A'] = '(';
		mp['B'] = ')';
		mp['C'] = '(';
		int flag = 0;
		string ans = "";
		for(auto p:str){
			ans += mp[p];
		}
		flag += check(ans);

		mp['A'] = '(';
		mp['B'] = '(';
		mp['C'] = ')';
		
		
		
		 ans = "";
		for(auto p:str){
			ans += mp[p];
		}
		flag += check(ans);

		ans = "";
		mp['A'] = '(';
		mp['B'] = ')';
		mp['C'] = ')';
		
		 ans = "";
		for(auto p:str){
			ans += mp[p];
		}
		flag += check(ans);
		ans = "";
		mp['A'] = ')';
		mp['B'] = '(';
		mp['C'] = '(';
		
		 ans = "";
		for(auto p:str){
			ans += mp[p];
		}
		flag += check(ans);
		ans = "";
		mp['A'] = ')';
		mp['B'] = ')';
		mp['C'] = '(';
		
		 ans = "";
		for(auto p:str){
			ans += mp[p];
		}
		flag += check(ans);
		ans = "";
		mp['A'] = ')';
		mp['B'] = '(';
		mp['C'] = ')';
		
		ans = "";
		for(auto p:str){
			ans += mp[p];
		}
		flag += check(ans);

		if(flag){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
}