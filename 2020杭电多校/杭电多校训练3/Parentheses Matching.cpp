#include<bits/stdc++.h>
using namespace std;
#define int long long 
int read(){
	int p;
	scanf("%lld",&p);
	return p;
}
const int N =  2e5+5;

signed main(){
	int t;
	t = read();
	while(t--){
		string s;
		cin >> s;
		int cnt = 0;
		int pcnt = 0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='(')cnt++;
			if(s[i]==')')cnt--;
			if(cnt < 0){
				cnt++;
				pcnt++;
			}
		}
		for(int i=0;i<s.length();i++){
			if(s[i]=='*'){
				if(pcnt){
					pcnt--;
					s[i] = '(';
				}
			}
		}
		int flag = 1;
		if(pcnt!=0){
			flag = 0;pcnt = 0;
		}
		cnt = 0;
		for(int i=s.length()-1;~i;i--){
			if(s[i]==')')cnt++;
			if(s[i]=='(')cnt--;
			if(cnt < 0){
				pcnt++;
				cnt++;
			}
		}
		for(int i=s.length()-1;~i;i--){
			if(s[i]=='*'){
				if(pcnt){
					s[i] = ')';
					pcnt--;
				}
			}
		}
		if(pcnt!=0){
			flag =0;
		}
		int cntt = 0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='(')cntt++;
			if(s[i]==')')cntt--;
			if(cntt<0){
				flag = 0;break;
			}
		}
		if(cntt!=0){
			flag = 0;
		}
		if(flag){
			for(int i=0;i<s.length();i++){
				if(s[i]!='*'){
					cout<<s[i];
				}
			}cout << endl;
		}else{
			cout << "No solution!" << endl;
		}
	}
}