#include<bits/stdc++.h>
using namespace std;
#define int long long
char c;
string a,b;
string sum2(string s1,string s2)
{
	if(s1.length()<s2.length())
	{
		string temp=s1;
		s1=s2;
		s2=temp;
	}
	int i,j;
	for(i=s1.length()-1,j=s2.length()-1;i>=0;i--,j--)
	{
		s1[i]=char(s1[i]+(j>=0?s2[j]-'0':0));   
		if(s1[i]-'0'>=10)
		{
			s1[i]=char((s1[i]-'0')%10+'0');
			if(i) s1[i-1]++;
			else s1='1'+s1;
		}
	}
	return s1;
}
signed main(){
	int sum = 0;
	int t;
	cin>>t;	
	for(int o = 1; o <= t; o++){cin>>a>>b;
		cout<<"Case "<<o<<":\n";
		
		string s = sum2(a,b);
		cout<<a<<" + "<<b<<" = "<<s<<endl;
		if(t!=o)cout<<endl;
	}
	
}
