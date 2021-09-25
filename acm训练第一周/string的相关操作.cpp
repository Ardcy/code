#include<bits/stdc++.h>
using namespace std;
string a(""); 
string b = "abcdefghijklmnopqrstuvwxyz";
string c(b,10);
int main(){
	cout<<c<<endl;
	cout<<c.empty()<<endl;
	
	cout<<c.size()<<endl;
	cout<<c.length()<<endl;
	string d(b,10);
	cout<<(c==d)<<endl;
	a = c+d;
	cout<<a<<endl;
	a += "1";
	cout<<a<<endl;
	//cin>>s 以空白为结束
	// getline(cin,s)可以读取一整行
	for(auto c:a){
		cout<<c;
	} 
	
	cout<<endl;
	cout<<a.find("mn")<<endl;
	cout<<a.rfind("mn")<<endl;
	cout<<a.find_first_of("mn")<<endl;
	//找到a中第一次出现mn任何字符的位置 
	// to_string; 
	int e = 58585;
	string s;
	s.npos;
	s = to_string(e);
	cout<<s<<endl;
	/*
	isalpha(c)
	isdigit(c)
	islower(c)
	toupper(c)
	转成大写字母 
	tolower(c)
	转成小写字母
	find 
	*/
	//while(cin>>a);
}

// 补充s.substr(位置（0->s.length()-1,长度）) 
