#include<bits/stdc++.h>
using namespace std;


#define int long long


int get(char y){
	if(y>='0'&&y<='9'){
		return (y-'0');
	}else{
		return (10+(y-'A'));
	}
}
int zh(string a,int p){
	int u = 1;
	int ans = 0;


	for(int i=a.length()-1;~i;i--){
		ans += get(a[i])*u;
		u*=p; 
	}
	return ans;
}

bool pcheck(string a,int p){

	for(int i=0;i<a.length();i++){
		if((a[i]>='A')&&(a[i]<='F')){
			if(a[i]-'A' >= p-10){
				return false;
			}
		}
		else{
			if(a[i]-'0' >= p){
				return false;
			}
		}
	}
	return true;
}

bool check(string a,string b,string c,char x,int p){

	if(!(pcheck(a,p)&&pcheck(b,p)&&pcheck(c,p))){
		return false;
	}
	int A,B,C;
	A = zh(a,p);
	B = zh(b,p);
	C = zh(c,p);
	if(x == '+'){
		if(A+B==C){
			return true;
		}
	}
	if(x=='-'){
		if(A-B==C)return true;
	}
	if((x=='*')&&(A*B==C))return true;
	if((x=='/')&&(A==B*C))return true;
	return false;
}

void solve(string s){
	string a,b,c;
	set<char>st;
	st.insert('+');st.insert('-');
	st.insert('*');st.insert('/');
	int idx=0;
	for(int i=0;i<s.length();i++){
		if(!st.count(s[i])){
			a+=s[i];
			idx++;
		}else{
			break;
		}
	}
	st.insert('=');
	char y;
	y = s[idx];
	idx++;
	for(int i=idx;i<s.length();i++){
		if(!st.count(s[i])){
			b+=s[i];
			idx++;
		}else{
			break;
		}
	}
	c = s.substr(idx+1,s.length() - idx - 1);
	// cout << a  << endl;
	// cout << b << endl;
	// cout << c << endl;
	// cout << y << endl;
	for(int i=2;i<=16;i++){
		if(check(a,b,c,y,i))
		{
			cout << i << endl;
			return;
		}
	}
	cout << -1 << endl;
}

signed main(){
	string s;
	while(cin>>s){
		solve(s);
	}
	

}