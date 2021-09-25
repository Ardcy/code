#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
#define int long long
string s;
int a[200][200];
signed main(){
	int n;
	cin>>n;
	cin>>s;
	cout<<s<<endl;
	int cnt = 0;
	a[0][(int)s[0]]=1;
	for(int i=0;i<=s.length()-2;i++){
		if(a[i][s[i+1]+1]==1){
			cnt++;
			
		} 
		else if(a[i][s[i+1]-1]==1){
			a[i+1][(int)s[i+1]]=1;
			a[i+1][(int)s[i+1]-1]=a[i][(int)s[i+1]-1];
		
			debug((char)(s[i+1]-1));
			debug((char)(s[i+1]+1));
			cnt++;
		}
		a[i+1][(int)s[i+1]]=1;
	
	}
	cout<<cnt<<endl;
	return 0;
}
