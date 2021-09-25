#include <iostream> 
#include <cstdio> 
#include <fstream> 
#include <algorithm> 
#include <cmath> 
#include <deque> 
#include <vector> 
#include <queue> 
#include <string> 
#include <cstring> 
#include <map> 
#include <stack> 
#include <set>
using namespace std;
signed main(){
	string s;
	string t="doge";
	int ans = 0;
	while(cin>>s){
		if(s=="EOF")break;
		int l=s.length()-3;
		for(int i=0;i<l;i++)
		{
			int f = 1;
			for(int j=0;j<4;j++){
				if(s[i+j]>='A'&&s[i+j]<='Z')s[i+j]=s[i+j]-'A'+'a';
				if(s[i+j]!=t[j])f=0;
			}
			if(f==1)ans++,i+=3;
				
		}
	}
	cout<<ans<<endl;
	return 0;
}
