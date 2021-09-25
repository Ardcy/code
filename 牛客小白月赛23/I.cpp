#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    string t;
    cin>>s;
	t=s[0];
	int cnt = 0;
    for(int i=1;i<s.length();i++){
    	cnt = 0;
    	while(s[i]==t[cnt]){
    		t+=s[i];
			cnt++;i++;
		}
		if(s[i]>t[cnt]){
			t=s.substr(i-cnt,cnt+1);
		}
		else t+=s[i];
	}
    cout<<t<<endl;
}
