#include<bits/stdc++.h>
using namespace std;
#define int long long
char D[200000];
signed main(){
	int T;
	cin>>T;
	while(T--){
		int a;
		cin>>a;
		cin>>D;
		int b=0,c=0,d=0;
		for(int i=0;i<a;i++){
			if(D[i]=='(')b++;
			if(D[i]==')'){
				if(b>0)b--;
				else c++;
			}
		}
		cout<<b+c<<endl;
	}
}
