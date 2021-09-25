#include<bits/stdc++.h>
using namespace std;


signed main(){
	int n;
	cin >> n;
	map<char,string>mp;
	mp['0'] = "0000";
	mp['1'] = "0001";
	mp['2'] = "0010";
	mp['3'] = "0011";
	mp['4'] = "0100";
	mp['5'] = "0101";
	mp['6'] = "0110";
	mp['7'] = "0111";
	mp['8'] = "1000";
	mp['9'] = "1001";
	mp['a'] = "1010";
	mp['b'] = "1011";
	mp['c'] = "1100";
	mp['d'] = "1101";
	mp['e'] = "1110";
	mp['f'] = "1111";
	for(int i1=1;i<=n;i1++){

		string s,t;
		cin >> s >> t;
		string ans1="" ,ans2="";
		for(int i=0;i<s.length();i++){
			ans1 += mp[s[i]];
		}
		for(int i=0;i<t.length();i++){
			ans2 += mp[t[i]];
		}
		// ans1 = get_nozero(ans1);
		// cout << " ---------" <<endl;
		// cout << " ans1 = " << ans1 << endl;
		// cout << " ans2 = " << ans2 << endl;

		int x =  -1;
		for(int i=0;i<ans1.length();i++){
			if(ans1[i]=='0'){
				x++;
			}else{
				break;
			}
		}
		x++;
		if(x!=ans1.length())
		ans1 = (ans1.substr(x,ans1.length() - x));
		x = -1;
		for(int i=0;i<ans2.length();i++){
			if(ans2[i]=='0'){
				x++;
			}else{
				break;
			}
		}
		x++;
		if(x!=ans2.length())
		ans2 = (ans2.substr(x,ans2.length() - x));
		

		// cout << " ans1 = " << ans1 << endl;
		// cout << " ans2 = " << ans2 << endl;
		string ans;
		for(int i=0;i<min(ans1.length(),ans2.length());i++){
			if(ans1[i]==ans2[i]){
				ans += ans1[i];
			}else{
				break;
			}
		}
		cout << ans << endl;
		cout << " 答案是：" <<endl;
		string ans3;
		int n1 = (ans.length() + 4) / 4;
		int cnt = 0;
		int pre = 0;
		map<int,int>np;
		np[0] = 1;
		np[1] = 2;
		np[2] = 4;
		np[3]  =8;
		for(int i=ans.length()-1;~i;i--){

			pre += np[cnt]* (ans[i]-'0');
			cnt++;
			if(cnt==4){
				if(pre >= 10){
					ans3+=(pre-10+'a');
				}else{
					ans3+=(pre+'0');
				}
				cnt = 0;
				pre = 0;
			}
		}
		if(pre >= 10){
			ans3+=(pre-10+'a');
		}else if(pre!=0){
			ans3+=(pre+'0');
		}
		cnt = 0;
		pre = 0;
		cout <<"Case #" << i1 << ": ";
		for(int i=ans3.length()-1;~i;i--){
			cout << ans3[i];
		}cout<<endl;

	}
}