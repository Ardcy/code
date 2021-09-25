#include<bits/stdc++.h>
using namespace std;
#define int long long
char s[1005000];
int cnt = 0;
signed main() {
	char c;
	int f = 0;
	while((c=getchar())!='\n'){
		if(c=='('||c=='{'||c=='[')
			s[++cnt]=c;
		else{
			if((s[cnt]=='('&&c==')')||(s[cnt]=='['&&c==']')||(s[cnt]=='{'&&c=='}')){
				cnt--;	
				if(cnt<0)
			}
			else
			{
				f = 1;
				break;
			}
			
		}
	}
	if(f == 1||cnt!=0)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
}
