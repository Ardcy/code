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
	//cin>>s �Կհ�Ϊ����
	// getline(cin,s)���Զ�ȡһ����
	for(auto c:a){
		cout<<c;
	} 
	
	cout<<endl;
	cout<<a.find("mn")<<endl;
	cout<<a.rfind("mn")<<endl;
	cout<<a.find_first_of("mn")<<endl;
	//�ҵ�a�е�һ�γ���mn�κ��ַ���λ�� 
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
	ת�ɴ�д��ĸ 
	tolower(c)
	ת��Сд��ĸ
	find 
	*/
	//while(cin>>a);
}

// ����s.substr(λ�ã�0->s.length()-1,���ȣ�) 
