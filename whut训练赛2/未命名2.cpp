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
inline int hashe(string s){
	int ans  = 0;
	for(int i=0;i<4;i++){
		ans*=26;
		ans+=s[i]-'a'; 
	}
	return ans;
}
int d[1000000];
signed main(){
	int n;
	cin>>n;
	string s="aaaa",t;
	for(int i=1;i<=n-3;i++){
		d[hashe(s.substr(i,4))]=1;
		int f = 0;
		for(int j=0;j<26;j++){
			 t = s.substr(i+1,3);
			t+=(j+'a');	
			if(d[hashe(t)]==0)break;
			f++;
		}
		if(f==26){cout<<i<<endl;break;}
		s+=t[3];
	}
	
	return 0;
}
