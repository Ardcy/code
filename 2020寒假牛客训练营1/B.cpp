#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;

signed main(){
	int a=0,b=0;
	int n;
	cin>>n;
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='6')a++;
		if(s[i]=='1')b++;
	}
	if(a>=b+1)cout<<b<<endl;
	else cout<<(a-1)<<endl;
}
