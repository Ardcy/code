#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<"="<<x<<endl 
using namespace std;
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
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        int t = 0, f = 0;
        int h = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]>='0'&&s[i]<='9')h++;
            if(s[i]=='+')t++,f=i;
        }
        //debug(t);
        //debug(f);
        //debug(h);
        //debug(s.length());
        if(h+t==s.length()&&f>0&&f<s.length()-1)
            cout<<sum2(s.substr(0,f),s.substr(f+1,s.length()-f))<<endl;
        else
        	cout<<"skipped"<<endl;
    }
}
