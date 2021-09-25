#include<bits/stdc++.h>
#define ll long long
#define debug(x) cerr<<#x<<'='<<x<<endl
using namespace std;
int main()
{
    int T;
    cin>>T;
    int a[26],b[26],c[26]; 
	while(T--){
		string s;
		cin>>s;
		for(int i =0;i<=25;i++)a[i]=-1,b[i]=-1,c[i]=0;
		for(int i=1;i<s.length();i++){
			if(a[s[i]-'a']==s[i-1]-'a'||b[s[i]-'a']==s[i-1]-'a'){
				continue;
			}
			if(a[s[i]-'a']==-1||b[s[i]-'a']==-1){
				
				if(a[s[i]-'a']==-1&&b[s[i-1]-'a']==-1){
				 	a[s[i]-'a']=s[i-1]-'a';
				 	b[s[i-1]-'a']=s[i]-'a';
				 	
				}
				else if(b[s[i]-'a']==-1&&a[s[i-1]-'a']==-1){
				 	b[s[i]-'a']=s[i-1]-'a';
				 	a[s[i-1]-'a']=s[i]-'a';
				}	
				 else {
				 	cout<<"NO"<<endl;
			 		break;
			 	}
			 	continue;
			}

			cout<<"NO"<<endl;
			break;		 
		}
		
		
		 int y = -1,k;
		 for(int i=0;i<=25;i++){
		 	if(a[i]==-1&&b[i]!=-1)y=i;

		 }
		 if(y==-1){
		 	cout<<"NO"<<endl;
		 	continue;
		 }
		 cout<<"YES"<<endl;
		 while(b[y]!=-1&&c[y]==0){
		 	cout<<(char)(y+'a');
		 	//debug(y);
			c[y]=1;
		 	y = b[y];
		 	//debug((b[y]));
		 	//debug((c[y]));
		 	
		 }
		 if(b[y]==-1&&a[y]!=-1)cout<<(char)(y+'a');
		 for(int i = 0;i<=25;i++)
		 {
		 	if(a[i]==-1&&b[i]==-1)cout<<(char)('a'+i);
		 }
		 cout<<endl;
	} 
    return 0;
}
