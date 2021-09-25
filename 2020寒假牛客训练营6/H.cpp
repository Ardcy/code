#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<'='<<x<<endl
#define int long long
int mod = 1;

int modd;
int val;
signed main() {
	{
		char str[10];
		int g = (26*26*26*26*26*26)-1;
		while(~scanf("%s",&str)){
			string answer="anbnds";
			cin>>modd;
			mod = modd;
			int res = 0,ans = 0;
	    	for (int i = 0; i < 6; i++)
	    	{
	       	 	res = (res * 26 + str[i] - 'a') % mod;
				ans = (ans * 26 + str[i] - 'a') ;
	    	}
	    	ans += mod;
	    	if(ans>g){
	    		cout<<"-1"<<endl;
	    		continue;
			}
	    	for(int i=5;i>=0;i--){
	    		answer[i]=(char)(ans%26+'a');
	    		ans/=26;
			}
			cout<<answer<<endl;	
		}
	}
}
